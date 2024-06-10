#include "VehControls-Traction_Control.h"

volatile unsigned long count = 0;
const float Kp = 1.0;
const float Ki = 1.0;
const float Kd = 1.0;
const float maxSlipRatio = 0.20;
const int minSpeed = 10;
float prev_error = 0;
float vehicleSpeed = 0.0;
unsigned currentTime = 0;// in milliseconds
float wheelSpeedFrL = 0.0;
float wheelSpeedFrR = 0.0;
float wheelSpeedReL = 0.0;
float wheelSpeedReR = 0.0;

void setup() {
  Serial.begin(9600);
  // Calling interrupt on rising edge to get individual wheel speeds
  
  attachInterrupt(digitalPinToInterrupt(A1), countPulse, RISING);
  attachInterrupt(digitalPinToInterrupt(A2), countPulse, RISING);
  attachInterrupt(digitalPinToInterrupt(A3), countPulse, RISING);
  attachInterrupt(digitalPinToInterrupt(A4), countPulse, RISING);
}

// ------------------------------------------------------------------------------------------------------------
// Begin Loop
// ------------------------------------------------------------------------------------------------------------
void loop() {

}

void countPulse() {
  count++;
}

void tractionControl(){

}