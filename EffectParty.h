// EffectParty.h

#include "Effect.h"

#ifndef _EFFECTPARTY_h
#define _EFFECTPARTY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EffectParty : public Effect {
  EffectParty(Adafruit_NeoPixel & side, Adafruit_NeoPixel & edge) : Effect(side, edge, "EffectParty") {};
  ~EffectParty() {};
  void
    update(uint8_t* buffer),
    tick();
};

#endif

