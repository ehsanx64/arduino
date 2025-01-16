#include <Arduino.h>
// #include "../../config.h"
#include "led.h"


void Led_Setup() {
    Serial.println("Led_Setup()");
}

void Led_Loop() {
    Serial.println("Led_Loop()");
}

#ifdef LED_ENABLED
void Led_Main() {
    Serial.println("Led_Main()");
}
#endif