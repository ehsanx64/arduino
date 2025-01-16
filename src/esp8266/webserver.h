#ifndef ESP8266_WEB_SERVER_H
#define ESP8266_WEB_SERVER_H

void Esp8266_WebServer_Setup();
void Esp8266_WebServer_Loop();

#ifdef ESP8266_WEB_SERVER_ENABLED
void Esp8266_WebServer_NotFoundHandler();
#endif // ESP8266_WEB_SERVER_ENABLED

#endif
