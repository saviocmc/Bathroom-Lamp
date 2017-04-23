#include <Arduino.h>
#include <Relay.h>

Relay lamp(9);

uint8_t const doorButtonPin = 10;

bool isDoorButtonPressed() {
	return !digitalRead(doorButtonPin);
}

void setup() {
	pinMode(doorButtonPin, INPUT_PULLUP);
}

void loop() {
	if (isDoorButtonPressed()) lamp.setState(ON);
	else lamp.setState(OFF);
	delay(100);
}
