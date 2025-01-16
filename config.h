/*** Tone *************************/
#define TONE_ENABLED
#define TONE_MELODY_ENABLED

/*** ADC  *************************/
#define ADC_ENABLED
   
/*** LED  *************************/
#define LED_ENABLED

/*** Wire *************************/
#define WIRE_ENABLED

/*** Neopixel *********************/
#define NEOPIXEL_ENABLED
#define NEOPIXEL_WS2812B_ENABLED

/*** ESP8266 Core *****************/
#define ESP8266_CORE_ENABLED
// WIFI
#define ESP8266_WIFI_ENABLED
#define ESP8266_WIFI_AP_ENABLED
#define ESP8266_WIFI_AP_ESSID "Electrofruit"
#define ESP8266_WIFI_AP_PSKEY "ef0123456789"
#define ESP8266_WIFI_STA_ESSID "Electrofruit"
#define ESP8266_WIFI_STA_PSKEY "ef0123456789"
// mDNS
#define ESP8266_MDNS_NAME "Electrofruit"
// OTA
#define ESP8266_OTA_ENABLED
#define ESP8266_OTA_HOSTNAME MDNS_NAME
// Web Server
#define ESP8266_WEB_SERVER_ENABLED
// Wemos D1 Mini
#define ESP8266_WEMOSD1MINI_ENABLED


/*** MQTT *************************/
#define MQTT_ENABLED
#define MQTT_BROKER_IP "0.0.0.0"
#define MQTT_BROKER_PORT 1883
#define MQTT_BROKER_USERNAME "user"
#define MQTT_BROKER_PASSWORD "pass"
#define MQTT_BROKER_TOPIC "testing"
#define MQTT_CLIENT_NAME "ArduinoPubSubClient"

/*** ATMEGA8 Core *****************/
//#define ATMEGA8_CORE_ENABLED

/*** Car **************************/
// Torret
//#define TORRET_ENABLED

/*** Software Serial **************/
#define SOFTWARE_SERIAL_ENABLED

#define LOGGING
