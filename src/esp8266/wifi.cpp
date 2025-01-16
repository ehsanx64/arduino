#include <Arduino.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
// #include <WiFiUdp.h>
#include "../../config.h"
#include "wifi.h"

void Esp8266_Wifi_Setup() {
#ifdef ESP8266_WIFI_ENABLED
#ifdef ESP8266_WIFI_AP_ENABLED
    // Set the module as a Wifi access point
    Serial.println("Setting WiFi Soft AP ... ");
    if (WiFi.softAP(ESP8266_WIFI_AP_ESSID, ESP8266_WIFI_AP_PSKEY)) {
        Serial.println("Access point ready!");
        Serial.printf("ESSID: %s\nPSKEY: %S\n", 
            ESP8266_WIFI_AP_ESSID, ESP8266_WIFI_AP_PSKEY);
    } else {
        Serial.println("Failed!");
    }

#else
    // If Wifi access point is not enabled, we'll continue as a station
    WiFi.mode(WIFI_STA);
    WiFi.begin(ESP8266_WIFI_STA_ESSID, ESP8266_WIFI_STA_PSKEY);

    // Wait for connection
    Serial.printf("Trying to connect to '%s' ", ESP8266_WIFI_STA_ESSID);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
#endif // WIFI_AP_ENABLED

    if (MDNS.begin(ESP8266_MDNS_NAME)) {
        Serial.println("MDNS Name: " + String(ESP8266_MDNS_NAME));
    }
#endif // ESP8266_WIFI_ENABLED
}

void Esp8266_Wifi_Loop() {
#ifdef ESP8266_WIFI_ENABLED
    MDNS.update();
#endif
}