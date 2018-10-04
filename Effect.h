// Effect.h

#include <Adafruit_NeoPixel.h>

#ifndef _EFFECT_h
#define _EFFECT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Effect {

public:
  Effect(Adafruit_NeoPixel & side, Adafruit_NeoPixel & edge) { side_strip = side; edge_strip = edge; };
  Effect(Adafruit_NeoPixel & side, Adafruit_NeoPixel & edge, String nameIn) { side_strip = side, edge_strip = edge; name = nameIn; };
  virtual
    ~Effect() = 0;
  virtual void
    update(uint8_t* buffer) = 0,
    tick() = 0;

  String name = "Unnamed Effect";
protected:
  Adafruit_NeoPixel
    side_strip,
    edge_strip;
};

inline Effect::~Effect() {};

#endif