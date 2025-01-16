
#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#define NEOPIX_PIN 8
#define NEOPIX_COUNT 8

void NeoPixel_Setup();
void NeoPixel_Loop();
void neopix_loop();
void set_neopixel(int val);
void set_brightness(int val);
void set_pixel(int red);

#ifdef NEOPIXEL_WS2812B_ENABLED
#define NEOPIXEL_PIN 5
void rgb_off();
void rgb_purple();
void rgb_green();
void rgb_blue();
void rgb_red();
void rgb_loop();
#endif

#endif
