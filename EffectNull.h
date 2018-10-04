// EffectNull.h

#include "Effect.h"

#ifndef _EFFECTNULL_h
#define _EFFECTNULL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EffectNull : public Effect {
public:
  EffectNull(Adafruit_NeoPixel & side, Adafruit_NeoPixel & edge) : Effect(side, edge, "EffectNull") {};
  ~EffectNull() {};
  void
    update(uint8_t* buffer);
  inline void
    tick() {};
};

#endif

