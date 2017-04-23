/**
* @author Sávio Carlos Martins Costa
**/

#include <Arduino.h>
#include <Relay.h>

Relay lamp(9);

uint8_t const doorButtonPin = 10;

// This is the time that the lamp will stay ON if (and only if) when the microcontroller
// is turned on, the door is open. If the door is closed before these timeout is over
// then it won't matter anymore and the lamp will be turned off as soon as the door is open again.
uint64_t const timeout = 10 * 60 * 1000; // 10 minutes

bool isTheDoorOpen() {
	return digitalRead(doorButtonPin);
}

void setup() {
	pinMode(doorButtonPin, INPUT_PULLUP);
	// When the microcontroller is turned on, the lamp should be turned on as well
	// no matters if the door is open or close.
	lamp.setState(ON);
	// Let the lamp stay ON until the door is closed for the first time or the initial timeout is over
	while (isTheDoorOpen() && millis() < timeout); // Wait here while the door still open and the timeout is not over.
	//Once the door is closed (or the timeout over), the "loop" will take place
}

void loop() {
	if (isTheDoorOpen()) lamp.setState(OFF);
	else lamp.setState(ON);
	delay(100);
}
