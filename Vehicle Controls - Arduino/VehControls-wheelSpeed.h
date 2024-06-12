#ifndef WHEELSPEED_H
#define WHEELSPEED_H
#include <Arduino.h>

extern const int sensorPins[];
extern volatile unsigned long wheelPulses[];
extern const float wheelCircumference;
extern const unsigned long timeInterval;
extern unsigned long previousTime;

void wheelSpeedSetup();
void wheelSpeedCalc(unsigned long wheelSpeeds[4]);

#endif
