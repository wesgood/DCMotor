#ifndef DCMotor_h
#define DCMotor_h

class DCMotor {
	public:
		DCMotor(uint8_t _enaPin, uint8_t _enbPin, uint8_t _speedPin);
		void stop();
		void coast();
		void setOutput(uint8_t _speed);
		
		uint8_t enaPin, enbPin, speedPin, speed;
	
	private:
		void goForward();
		void goBackward();
};

#endif