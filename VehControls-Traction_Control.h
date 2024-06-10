#ifndef TRACTIONCONTROL_H
#define TRACTIONCONTROL_H
#include <Arduino.h>

void tractionControlSetup();
void tractionControlAlgorithm(unsigned long wheelSpeeds[4]);

#endif