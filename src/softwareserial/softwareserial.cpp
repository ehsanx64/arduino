#include <Arduino.h>
#include <SoftwareSerial.h>
#include "softwareserial.h"

#ifdef SOFTWARE_SERIAL_ENABLED
EspSoftwareSerial::UART ssw;
#endif

void SoftwareSerial_Setup() {
#ifdef SOFTWARE_SERIAL_ENABLED
    ssw.begin(19200, SWSERIAL_8N1, SSW_RX, SSW_TX, false);

    if (!ssw) {
        Serial.println("Failed to initialize ssw");
        while (1) delay(1000);
    } else {
        Serial.println("ssw initialized");
    }
#endif
}
