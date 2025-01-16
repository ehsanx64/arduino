#ifndef ATMEGA8_CORE_H
#define ATMEGA8_CORE_H

void Atmega8Core_Setup();
void Atmega8Core_Loop();

#ifdef ATMEGA8_CORE_ENABLED
void Atmega8Core_Main();

void all_off();
#endif // ATMEGA8_CORE_ENABLED

#endif
