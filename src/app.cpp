#include "app.h"
#include "tone/tone.h"
#include "adc/adc.h"
#include "led/led.h"
#include "wire/wire.h"
#include "neopixel/neopixel.h"
#include "esp8266/core.h"
#include "atmega8/core.h"
#include "car/torret.h"

void App_Setup() {
    Tone_Setup();
    Adc_Setup();
    Led_Setup();
    Wire_Setup();
    NeoPixel_Setup();
    Esp8266Core_Setup();
}

void App_Loop() {
    Tone_Loop();
    Adc_Loop();
    Led_Loop();
    Wire_Loop();
    NeoPixel_Loop();
    Esp8266Core_Loop();
}
