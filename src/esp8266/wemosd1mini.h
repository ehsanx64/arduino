#ifndef ESP8266_WEMOSD1MINI_H
#define ESP8266_WEMOSD1MINI_H

void Esp8266_WemosD1Mini_Setup();
void Esp8266_WemosD1Mini_Loop();

#ifdef ESP8266_WEMOSD1MINI_ENABLED
void setColor(uint32_t color);
int getDelay();
#endif // ESP8266_WEMOSD1MINI_ENABLED
#endif // ESP8266_WEMOSD1MINI_H
