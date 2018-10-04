// 
// 
// 

#include "EffectChase.h"

EffectChase::~EffectChase()
{
}

void EffectChase::update(uint8_t * buffer)
{
  Serial.println("EChase Update Begin");
  scolour = side_strip.Color(buffer[0], buffer[1], buffer[2]);
  scolour2 = side_strip.Color(buffer[3], buffer[4], buffer[5]);
  ecolour = edge_strip.Color(buffer[0], buffer[1], buffer[2]);
  ecolour2 = edge_strip.Color(buffer[3], buffer[4], buffer[5]);
  speed = buffer[6];
  chase_len = buffer[7] + 1;
}

void EffectChase::tick()
{
  if (time + speed < millis()) {
    time = millis();
    for (uint16_t i = side_strip.numPixels() - 1; i > 0; i--) {
      side_strip.setPixelColor(i, side_strip.getPixelColor(i - 1));
    }
    for (uint16_t i = edge_strip.numPixels() - 1; i > 0; i--) {
      edge_strip.setPixelColor(i, edge_strip.getPixelColor(i - 1));
    }
    if (cycle++ < chase_len) {
      side_strip.setPixelColor(0, scolour);
      edge_strip.setPixelColor(0, ecolour);
    }
    else {
      side_strip.setPixelColor(0, scolour2);
      edge_strip.setPixelColor(0, ecolour2);
    }
    if (cycle >= (chase_len * 2)) cycle = 0;
    side_strip.show();
    edge_strip.show();
  }
}
