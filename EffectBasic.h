// EffectBasic.h

#include "Effect.h"

#ifndef _EFFECTBASIC_h
#define _EFFECTBASIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EffectBasic : public Effect {
public:
  EffectBasic(Adafruit_NeoPixel & side, Adafruit_NeoPixel & edge) : Effect(side, edge, "EffectBasic") {};
  ~EffectBasic();
  void
    update(uint8_t* buffer);
  inline void
    tick() {};
private:
};

#endif

