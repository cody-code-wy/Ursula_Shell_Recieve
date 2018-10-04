// EffectsLinkedList.h

#include "Effect.h"

#ifndef _EFFECTSLINKEDLIST_h
#define _EFFECTSLINKEDLIST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class EffectsLinkedList {
public:
  EffectsLinkedList(Effect * effectIn, uint8_t sizeIn) { effect = effectIn; size = sizeIn; held_effect_name = effect->name; };
  ~EffectsLinkedList() {};
 
  void
    addToEnd(EffectsLinkedList * input),
    replaceNext(EffectsLinkedList * input);

  EffectsLinkedList 
    * getLast(),
    * getNDeep(uint8_t N),
    * getNDeepPtr(uint8_t * N, boolean debug = false);

  Effect *
    getEffect();

  String
    held_effect_name;

private:
  EffectsLinkedList * next = nullptr;

  Effect *
    effect;

  uint8_t
    size;
};

#endif

