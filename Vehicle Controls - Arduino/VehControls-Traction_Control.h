#ifndef TRACTIONCONTROL_H
#define TRACTIONCONTROL_H
#include <Arduino.h>

extern float Kp;
extern float Ki;
extern float Kd;
extern const float desiredSlip;
extern double slip;
extern double prevError;
extern double integral;
extern double throttleOutput;
extern unsigned long prevTime;
extern const unsigned long sampleRate;

void tractionControlSetup();
void tractionControlAlgorithm(unsigned long wheelSpeeds[4]);

#endif
