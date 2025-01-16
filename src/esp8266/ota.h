#ifndef ESP8266_OTA_H
#define ESP8266_OTA_H

void Esp8266_Ota_Setup();
void Esp8266_Ota_Loop();

#ifndef ESP8266_OTA_ENABLED
void esp8266_ota_flash(int count);
#endif // ESP8266_OTA_ENABLED

#endif
