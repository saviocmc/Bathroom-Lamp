/**
* @author Sávio Carlos Martins Costa
*
* This is the "performance" branch. All code here will be minimized
* and optimized to get the minimum execution time.
**/

#include <Arduino.h>
#include <digitalWriteFast.h>

#define relayPin 0
#define doorButtonPin1 10
#define doorButtonPin2 11
#define timeout 300000 // 5 minutes

void setup() {
	pinModeFast(relayPin, OUTPUT);
	digitalWriteFast(relayPin, LOW);
	pinModeFast(doorButtonPin2, OUTPUT);
	digitalWriteFast(doorButtonPin2, LOW);
	pinMode(doorButtonPin1, INPUT_PULLUP);
	digitalWriteFast(doorButtonPin1, HIGH);
	while (digitalReadFast(doorButtonPin1) && millis() < timeout);
}

void loop() {
	digitalWriteFast(relayPin, digitalReadFast(doorButtonPin1));
	delay(100);
}
