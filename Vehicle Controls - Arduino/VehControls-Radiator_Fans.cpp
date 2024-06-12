#include "Arduino.h"
#include "VehControls-Radiator_Fans.h"

void radFanSetup(){
  pinMode(A0, INPUT);
}
void radFanControl(float CAN_coolantTemp){
  int coolantSensorValue = analogRead(A0);
  float coolantTemp = calcTemp(coolantSensorValue);
  CAN_coolantTemp = coolantTemp;

  if (coolantTemp < 170){
    analogWrite(2, 0);
  } else if (coolantTemp >= 190) {
    analogWrite(2, 255);
  } else {
    float fanPWM = (12.75 * coolantTemp) -2167.5;// linear relationship between 170-190°F and 0-255 PWM
    analogWrite(2, fanPWM);
  }

}

float calcTemp(int coolantSensorValue){
  float coolantVoltage = coolantSensorValue * (5.0/1023.0);
  float coolantResistance = (coolantVoltage * 1000)/(5 - coolantVoltage);// multiplying by pull-up resistor value, dividing by voltage difference
  float coolantTemp = (4.675 * coolantResistance) - 435.532;
  return coolantTemp;
}
