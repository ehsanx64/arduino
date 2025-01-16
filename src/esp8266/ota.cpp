#include <Arduino.h>
#include "../../config.h"
#include "ota.h"

#ifndef ESP8266_OTA_ENABLED
#include <ArduinoOTA.h>

// Constants
#define LED 2

// Functions
void esp8266_ota_flash(int count) {
	for (int i = 0; i < count; i++) {
		digitalWrite(LED, LOW);
		delay(50);
		digitalWrite(LED, HIGH);
		delay(100);
	}	
}
#endif // ESP8266_OTA_ENABLED

void Esp8266_Ota_Setup() {
#ifndef ESP8266_OTA_ENABLED
	pinMode(LED, OUTPUT);
	esp8266_ota_flash(2);

	// Hostname defaults to esp8266-[ChipID]
	ArduinoOTA.setHostname(ESP8266_OTA_HOSTNAME);
	
    ArduinoOTA.onStart([]() {
		String type;
		digitalWrite(LED, LOW);
		if (ArduinoOTA.getCommand() == U_FLASH) {
			type = "sketch";
		} else {  // U_FS
			type = "filesystem";
		}
		
		// NOTE: if updating FS this would be the place to unmount FS using FS.end()
		Serial.println("Start updating " + type);
	});
	
	ArduinoOTA.onEnd([]() {
		esp8266_ota_flash(10);
		Serial.println("\nEnd");
	});
	
	ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
		esp8266_ota_flash(1);
		Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
	});
	
	ArduinoOTA.onError([](ota_error_t error) {
		Serial.printf("Error[%u]: ", error);
		if (error == OTA_AUTH_ERROR) {
			Serial.println("Auth Failed");
		} else if (error == OTA_BEGIN_ERROR) {
			Serial.println("Begin Failed");
		} else if (error == OTA_CONNECT_ERROR) {
			Serial.println("Connect Failed");
		} else if (error == OTA_RECEIVE_ERROR) {
			Serial.println("Receive Failed");
		} else if (error == OTA_END_ERROR) {
			Serial.println("End Failed");
		}
	});
	
	ArduinoOTA.begin();
	digitalWrite(LED, LOW);
#endif // ESP8266_OTA_ENABLED
}

void Esp8266_Ota_Loop() {
#ifndef ESP8266_OTA_ENABLED
    ArduinoOTA.handle();
#endif // ESP8266_OTA_ENABLED
}