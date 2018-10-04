// EffectsManager.h

#include "Effect.h"
#include "EffectsLinkedList.h"

#ifndef _EFFECTSMANAGER_h
#define _EFFECTSMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EffectsManager {
public:
  EffectsManager() {};
  ~EffectsManager() {};

  void
    addEffect(Effect * effect_to_add, uint8_t size = 1),
    update(uint8_t * buffer),
    tick();
 
private:
  EffectsLinkedList *
    listStart = nullptr;

  Effect*
    getCurrentEffect();

  uint8_t
    current_program;

private:

};

#endif

