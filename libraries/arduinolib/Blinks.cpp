#include "Arduino.h"
#include "Blinks.h"

Blinks::Blinks(int pin) {
	pinMode(pin, OUTPUT);
	_pin = pin;
}

void Blinks::type1() {
	digitalWrite(_pin, HIGH);
	delay(500);
	digitalWrite(_pin, LOW);
	delay(1000);
}
