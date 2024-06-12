#ifndef FUELPUMP_H
#define FUELPUMP_H

#include <Arduino.h>

void fuelPumpSetup();
void fuelPumpControl(float CAN_MAP);

#endif