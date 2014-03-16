DCMotor
=======

A simple DC Motor h-bridge library for Arduino

## Methods

```
DCMotor(uint_8 _enaPin, uint8_t _enbPin, uint8_t _speedPin);
void stop();
void coast();
void setOutput(uint8_t output);
```