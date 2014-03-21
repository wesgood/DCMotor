#include <Arduino.h>
#include "DCMotor.h"

/*
* @Constructor
*
* @param _enaPin enable pin A of h-bridge
* @param _enbPin enable pin B of h-bridge
* @param _speedPin PWM output pin
*/
DCMotor::DCMotor(uint8_t _enaPin, uint8_t _enbPin, uint8_t _speedPin) {
	enaPin = _enaPin;
	enbPin = _enbPin;
	speedPin = _speedPin;
	speed = 0;
	
	pinMode(enaPin, OUTPUT);
	pinMode(enbPin, OUTPUT);
	pinMode(speedPin, OUTPUT);
	
	digitalWrite(enaPin, LOW);
	digitalWrite(enbPin, LOW);
	analogWrite(speedPin, 0);
}

/*
* Set motor speed
*
* @param _speed PWM value output ranging from -255 to 255
*/
void DCMotor::setOutput(uint8_t _speed) {
	speed = _speed;
	if (speed > 0) {
		goForward();
		analogWrite(speedPin, speed);
	} else if (speed < 0) {
		goBackward();
		analogWrite(speedPin, abs(speed));
	} else {
		coast();
	}
}

/*
* Set the motor to coast to a stop
*/
void DCMotor::coast() {
	digitalWrite(enaPin, LOW);
	digitalWrite(enbPin, LOW);
}

/*
* Instantly stop the motor by locking the enable pins
*/
void DCMotor::stop() {
	digitalWrite(enaPin, HIGH);
	digitalWrite(enbPin, HIGH);
}

/*
* Set the direction of the hbridge output forward
*/
void DCMotor::goForward() {
	digitalWrite(enaPin, HIGH);
	digitalWrite(enbPin, LOW);
}

/*
* Set the direction of the hbridge output backward
*/
void DCMotor::goBackward() {
	digitalWrite(enaPin, LOW);
	digitalWrite(enbPin, HIGH);
}