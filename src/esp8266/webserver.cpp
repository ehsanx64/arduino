#include <Arduino.h>
#include "../../config.h"
#include "webserver.h"

#ifdef ESP8266_WEB_SERVER_ENABLED
#include <ESP8266WebServer.h>
// Constants

// Variables
ESP8266WebServer webServer(80);

// Functions
void Esp8266_WebServer_NotFoundHandler() {
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += webServer.uri();
    message += "\nMethod: ";
    message += (webServer.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += webServer.args();
    message += "\n";
    
    for (uint8_t i = 0; i < webServer.args(); i++) {
        message += " " + webServer.argName(i) + ": " + webServer.arg(i) + "\n";
    }
    
    webServer.send(404, "text/plain", message);
}
#endif // ESP8266_WEB_SERVER_ENABLED

void Esp8266_WebServer_Setup() {
#ifdef ESP8266_WEB_SERVER_ENABLED
    webServer.onNotFound(Esp8266_WebServer_NotFoundHandler);

    webServer.addHook([](const String & method, const String & url, WiFiClient * client, ESP8266WebServer::ContentTypeFunction contentType) {
        (void)method;       // GET, PUT, ...
        (void)url;          // example: /root/myfile.html
        (void)client;       // the webserver tcp client connection
        (void)contentType;  // contentType(".html") => "text/html"
        Serial.printf("A useless web hook has passed\n");
        Serial.printf("(this hook is in 0x%08x area (401x=IRAM 402x=FLASH))\n", esp_get_program_counter());
        Serial.println("URL: " + url);
        Serial.println("Method: " + method);
        return ESP8266WebServer::CLIENT_REQUEST_CAN_CONTINUE;
    });

    webServer.begin();
#endif // ESP8266_WEB_SERVER_ENABLED
}

void Esp8266_WebServer_Loop() {
#ifdef ESP8266_WEB_SERVER_ENABLED
	webServer.handleClient();
#endif // ESP8266_WEB_SERVER_ENABLED
}