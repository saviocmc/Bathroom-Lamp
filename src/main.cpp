/**
* @author Sávio Carlos Martins Costa
*
* The goal of this project is to eliminate the energy waste when people
* leaves the bathroom leaving the light bulb ON.
**/

#include <Arduino.h>
#include <Relay.h>

// Instantiate a new Relay object attached to pin 0.
Relay lamp(0);

// The pins in which the door's "sensor" is attached to.
uint8_t const doorButtonPin1 = 10;
uint8_t const doorButtonPin2 = 11;

// This is the time (in milliseconds) that the lamp will stay ON if (and only if) when the microcontroller
// is turned on AND the door is open. If the door is closed before these timeout is over
// then it won't matter anymore and the lamp will be turned off as soon as the door is open again.
uint64_t const timeout = 300000; // 5 minutes

bool isTheDoorOpen() {
	return digitalRead(doorButtonPin1);
}

void setup() {
	// When the microcontroller is turned on, the lamp should be turned on as well
	// no matters if the door is open or close.
	lamp.setState(ON);
	// Set the mode of the door's "sensor" pins
	// One of them is the GND reference, the other is used with the built in Pullup resistor
	// Together they form a Pullup button.
	pinMode(doorButtonPin2, OUTPUT);
	digitalWrite(doorButtonPin2, LOW);
	pinMode(doorButtonPin1, INPUT_PULLUP);
	digitalWrite(doorButtonPin1, HIGH);
	// Let the lamp stay ON until the door is closed for the first time or the initial timeout is over.
	while (isTheDoorOpen() && millis() < timeout); // Wait here while the door still open and the timeout is not over.
	//Once the door is closed (or the timeout over), the "loop" will take place.
}

void loop() {
	if (isTheDoorOpen()) lamp.setState(OFF);
	else lamp.setState(ON);
	// This delay here is just to prevent the relay to be toggled too many times
	// in the period when the button (the door) is opening or closing.
	delay(100);
}
