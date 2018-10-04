// 
// 
// 

#include "EffectsLinkedList.h"

void EffectsLinkedList::addToEnd(EffectsLinkedList * input)
{
  getLast()->replaceNext(input);
}

void EffectsLinkedList::replaceNext(EffectsLinkedList * input)
{
  Serial.print("On ");
  Serial.print(size);
  Serial.print(" replace next with ");
  Serial.println(input->size);
  next = input;
}

EffectsLinkedList * EffectsLinkedList::getLast()
{
  if (next) { return next->getLast(); }
  return this;
}

EffectsLinkedList * EffectsLinkedList::getNDeepPtr(uint8_t * N, boolean debug)
{
  if (debug) {
    Serial.print("N:");
    Serial.print(*N);
    Serial.print(";T:");
    Serial.print(size);
    Serial.print(";E:");
    Serial.println(held_effect_name);
  }
  if (*N < size) {
    if (debug) { Serial.println("Found returning self"); }
    return this;
  }
  *N -= size;
  if (debug) {
    Serial.print("Not found trying next with N:");
    Serial.println(*N);
  }
  if (next) {
    return next->getNDeepPtr(N);
  }
  else {
    if (debug) { Serial.println("LAST EFFECT!\nReturning self"); }
    return this;
  }
}

Effect * EffectsLinkedList::getEffect()
{
  return effect;
}

EffectsLinkedList * EffectsLinkedList::getNDeep(uint8_t N)
{
  return getNDeepPtr(&N);
}
