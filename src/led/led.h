#ifndef LED_H
#define LED_H

void Led_Setup();
void Led_Loop();

#ifdef LED_ENABLED
void Led_Main();
#endif

#endif
