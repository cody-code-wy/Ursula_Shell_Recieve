// 
// 
// 

#include "EffectNull.h"

void EffectNull::update(uint8_t * buffer)
{
  side_strip.clear();
  side_strip.show();
  edge_strip.clear();
  edge_strip.show();
}
