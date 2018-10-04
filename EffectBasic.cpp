// 
// 
// 

#include "EffectBasic.h"

EffectBasic::~EffectBasic()
{
}

void EffectBasic::update(uint8_t * buffer)
{
  for (uint16_t i = 0; i < side_strip.numPixels(); i++) {
    side_strip.setPixelColor(i, buffer[0], buffer[1], buffer[2]);
  }
  side_strip.show();
  for (uint16_t i = 0; i < edge_strip.numPixels(); i++) {
    edge_strip.setPixelColor(i, buffer[3], buffer[4], buffer[5]);
  }
  edge_strip.show();
}
