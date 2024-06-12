#include "VehControls-Fuel_Pump.h"
#include "VehControls-Radiator_Fans.h"
#include "VehControls-wheelSpeed.h"
#include "VehControls-Traction_Control.h"

unsigned long wheelSpeeds[4] = {0, 0, 0, 0};
float CAN_coolantTemp;
float CAN_MAP;
// initial setup
void setup() {
    Serial.begin(9600);
    radFanSetup();
    fuelPumpSetup();
    wheelSpeedSetup();
    tractionControlSetup();
}

// loop
void loop() {
    radFanControl(CAN_coolantTemp);
    fuelPumpControl(CAN_MAP);
    wheelSpeedCalc(wheelSpeeds);
    tractionControlAlgorithm(wheelSpeeds);
    Serial.println(wheelSpeeds[0]);
    Serial.println(wheelSpeeds[1]);
    Serial.println(wheelSpeeds[2]);
    Serial.println(wheelSpeeds[3]);
    Serial.println(CAN_coolantTemp);
    Serial.println(CAN_MAP);
    delay(10);// operating at 100Hz
}