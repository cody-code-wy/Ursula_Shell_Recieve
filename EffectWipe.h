// EffectWipe.h

#include "Effect.h"

#ifndef _EFFECTWIPE_h
#define _EFFECTWIPE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EffectWipe : public Effect {
public:
  EffectWipe(Adafruit_NeoPixel & side, Adafruit_NeoPixel & edge) : Effect(side, edge, "EffectWipe") {};
  ~EffectWipe();
  void
    update(uint8_t* buffer),
    tick();
private:
  uint32_t
    scolour, ecolour = 0;
  uint8_t
    delay = 0;
  ulong
    time = 0;
};

#endif

