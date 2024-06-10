#ifndef RADFANS_H
#define RADFANS_H

#include <Arduino.h>

void radFanSetup();
void radFanControl(float CAN_coolantTemp);

#endif