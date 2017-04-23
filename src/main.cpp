/**
* @author Sávio Carlos Martins Costa
*
* This is the "performance" branch. All code here will be minimized
* and optimized to get the minimum execution time.
**/

#include <Arduino.h>
#include <digitalWriteFast.h>

uint8_t const relayPin = 9;
uint8_t const doorButtonPin = 10;
uint64_t const timeout = 600000; // 10 minutes

void setup() {
	pinModeFast(relayPin, OUTPUT);
	pinModeFast(doorButtonPin, INPUT_PULLUP);
	digitalWriteFast(relayPin, LOW);
	while (digitalReadFast(doorButtonPin) && millis() < timeout);
}

void loop() {
	digitalWriteFast(relayPin, digitalReadFast(doorButtonPin));
	delay(100);
}
