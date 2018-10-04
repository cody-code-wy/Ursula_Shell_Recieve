// 
// 
// 

#include "EffectWipe.h"

EffectWipe::~EffectWipe()
{
}

void EffectWipe::update(uint8_t* buffer)
{
  scolour = side_strip.Color(buffer[0], buffer[1], buffer[2]);
  ecolour = edge_strip.Color(buffer[3], buffer[4], buffer[5]);
  delay = buffer[6];
}

void EffectWipe::tick()
{
  if (time + delay < millis()) {
    time = millis();
    for (uint16_t i = side_strip.numPixels() - 1; i > 0; i--) {
      side_strip.setPixelColor(i, side_strip.getPixelColor(i - 1));
    }
    for (uint16_t i = edge_strip.numPixels() - 1; i > 0; i--) {
      edge_strip.setPixelColor(i, edge_strip.getPixelColor(i - 1));
    }
    side_strip.setPixelColor(0, scolour);
    edge_strip.setPixelColor(0, ecolour);
    side_strip.show();
    edge_strip.show();
  }
}
