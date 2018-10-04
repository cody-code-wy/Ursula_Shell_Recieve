// rf69 demo tx rx.pde
// -*- mode: C++ -*-
// Example sketch showing how to create a simple messageing client
// with the RH_RF69 class. RH_RF69 class does not provide for addressing or
// reliability, so you should only use RH_RF69  if you do not need the higher
// level messaging abilities.
// It is designed to work with the other example rf69_server.
// Demonstrates the use of AES encryption, setting the frequency and modem 
// configuration

#include "EffectsLinkedList.h"
#include "EffectsManager.h"
#include "EffectParty.h"
#include "EffectNull.h"
#include "EffectChase.h"
#include "EffectBasic.h"
#include "EffectWipe.h"
#include "Effect.h"
#include <SPI.h>
#include <RH_RF69.h>
#include <Adafruit_NeoPixel.h>

// Begin Radio Setup
// Change to 434.0 or other frequency, must match RX's freq!
#define RF69_FREQ 915.0

#define RFM69_CS      8
#define RFM69_INT     3
#define RFM69_RST     4
#define LED           13

#define ID 0

// Singleton instance of the radio driver
RH_RF69 rf69(RFM69_CS, RFM69_INT);

// End Radio Setup

/*********** Neopixel Setup ************/

#define SIDENPIN 11
#define EDGEPIN 12
Adafruit_NeoPixel side_strip(40, SIDENPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel edge_strip(36, EDGEPIN, NEO_GRB + NEO_KHZ800);

EffectsManager manager;

void setup()
{
  Serial.begin(115200);
  //while (!Serial) { delay(1); } // wait until serial console is open, remove if not tethered to computer

  pinMode(LED, OUTPUT);
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, LOW);

  Serial.println("Feather RFM69 RX");
  Serial.println();

  // manual reset
  digitalWrite(RFM69_RST, HIGH);
  delay(10);
  digitalWrite(RFM69_RST, LOW);
  delay(10);

  if (!rf69.init()) {
    Serial.println("RFM69 radio init failed");
    while (1);
  }
  Serial.println("RFM69 radio init OK!");

  // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM (for low power module)
  // No encryption
  if (!rf69.setFrequency(RF69_FREQ)) {
    Serial.println("setFrequency failed");
  }

  // If you are using a high power RF69 eg RFM69HW, you *must* set a Tx power with the
  // ishighpowermodule flag set like this:
  rf69.setTxPower(14, true);  // range from 14-20 for power, 2nd arg must be true for 69HCW

  // The encryption key has to be the same as the one in the server
  uint8_t key[] = { 0x1f, 0xf9, 0x04, 0x65, 0x31, 0xfd, 0x2c, 0xb3,
            0xa5, 0xcf, 0x0d, 0x18, 0xe5, 0x8e, 0x85, 0xc1 };
  rf69.setEncryptionKey(key);

  pinMode(LED, OUTPUT);

  Serial.print("RFM69 radio @");  Serial.print((int)RF69_FREQ);  Serial.println(" MHz");

  side_strip.begin();
  side_strip.clear();
  side_strip.show();

  edge_strip.begin();
  edge_strip.clear();
  edge_strip.show();

  manager.addEffect(new EffectNull(side_strip, edge_strip), 1); // 0 Blackout
  manager.addEffect(new EffectBasic(side_strip, edge_strip), 5); // 1-5 Basic
  manager.addEffect(new EffectWipe(side_strip, edge_strip), 5); // 6-10 Wipe
  manager.addEffect(new EffectChase(side_strip, edge_strip), 30); // 11-40 Chase
}


//EffectWipe wipe(side_strip);
//EffectChase chase(side_strip);
//EffectBasic basic(side_strip);
//EffectNull null_effect(side_strip);

ulong time = millis();

void loop() {
  manager.tick();
  if(time+80 < millis())
    digitalWrite(13, LOW);
  if (rf69.available()) {
    digitalWrite(13, HIGH);
    time = millis();
    uint8_t buf[RH_RF69_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf69.recv(buf, &len)) {
      if (!len) return;
      Serial.println(len);
      if (buf[0] != ID || len != 9) return;
      manager.update(&buf[1]);
    }
  }
}
