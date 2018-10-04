// EffectChase.h

#include "Effect.h"

#ifndef _EFFECTCHASE_h
#define _EFFECTCHASE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EffectChase : public Effect {
public:
  EffectChase(Adafruit_NeoPixel & side, Adafruit_NeoPixel & edge) : Effect(side, edge, "EffectChase") {};
  ~EffectChase();
  void 
    update(uint8_t* buffer),
    tick();
private:
  uint32_t
    scolour, scolour2, ecolour, ecolour2 = 0;
  uint8_t
    speed = 0,
    chase_len = 4,
    cycle = 0;
  ulong
    time = 0;
};

#endif

