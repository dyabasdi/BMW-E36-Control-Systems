#include "Arduino.h"
#include "VehControls-Fuel_Pump.h"

void fuelPumpSetup(){
  pinMode(A1, INPUT);//manifold air pressure sensor reading at this pin
}
void fuelPumpControl(int CAN_MAP){
  int mapSensorValue = analogRead(A1);
  float manifoldPressure = calcPressure(mapSensorValue);
  CAN_MAP = manifoldPressure / 6.89475729;//conversion to PSI for digital dash
  if (manifoldPressure > 0){
    analogWrite(3, 255);
  } else {
    analogWrite(3, 0);
  }
}

float calcPressure(int mapSensorValue){
  float mapSensorVoltage = mapSensorValue * (5.0/1023.0); //converting to voltage
  float manifoldPressureKPA = (mapSensorVoltage + (0.04*5.0))/(0.004*5.0);// linear relationship for voltage to KPA
  return manifoldPressureKPA;
}
