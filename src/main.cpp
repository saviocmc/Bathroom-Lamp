/**
* @author Sávio Carlos Martins Costa
*
* This is the "performance" branch. All code here will be minimized
* and optimized to get the minimum execution time.
**/

#include <Arduino.h>
#include <digitalWriteFast.h>

#define relayPin 9
#define doorButtonPin 10
#define timeout 600000 // 10 minutes

void setup() {
	pinModeFast(relayPin, OUTPUT);
	digitalWriteFast(relayPin, LOW);
	pinModeFast(doorButtonPin, INPUT_PULLUP);
	while (digitalReadFast(doorButtonPin) && millis() < timeout);
}

void loop() {
	digitalWriteFast(relayPin, digitalReadFast(doorButtonPin));
	delay(100);
}
