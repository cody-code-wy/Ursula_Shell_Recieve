// 
// 
// 

#include "EffectsManager.h"

void EffectsManager::update(uint8_t * buffer)
{
  //Serial.println("Begin Update");
  current_program = buffer[7];
  EffectsLinkedList * ell = listStart->getNDeepPtr(&buffer[7]);
  //Serial.print("Got ELL holding ");
  //Serial.println(ell->held_effect_name);
  Effect * effect = ell->getEffect();
  //Serial.print("Got Effect ");
  //Serial.println(effect->name);
  effect->update(buffer);
  //Serial.print("current_program==");
  //Serial.println(current_program);
  //Serial.println("End Update");
}

void EffectsManager::addEffect(Effect * effect_to_add, uint8_t size)
{
  if (listStart) {
    listStart->addToEnd(new EffectsLinkedList(effect_to_add, size));
  }
  else {
    listStart = new EffectsLinkedList(effect_to_add, size);
  }
}

Effect * EffectsManager::getCurrentEffect()
{
  return listStart->getNDeep(current_program)->getEffect();
}

void EffectsManager::tick()
{
  //Serial.println("Begin Tick");
  getCurrentEffect()->tick();
  //Serial.println("End Tick");
}
