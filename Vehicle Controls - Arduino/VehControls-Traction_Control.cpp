#include "Arduino.h"
#include "VehControls-Traction_Control.h"

float Kp = 1.0;
float Ki = 1.0;
float Kd = 1.0;
const float desiredSlip = 0.10;
double slip = 0;
double prevError = 0;
double integral = 0;
double throttleOutput = 0;
unsigned long prevTime = 0;
const unsigned long sampleRate = 10;

void tractionControlSetup() {
  // Output for throttle adjustment %
  pinMode(4, OUTPUT);
}

void tractionControlAlgorithm(unsigned long wheelSpeeds[4]){
  unsigned long currTime = millis();
  if (currTime - prevTime >= sampleRate){
    float vehicleSpeed = (wheelSpeeds[0] + wheelSpeeds[1])/2;// average of driven wheels (front wheels) = vehicle speed
    float wheelSlipFrL = (wheelSpeeds[0]/vehicleSpeed) - 1;
    float wheelSlipFrR = (wheelSpeeds[1]/vehicleSpeed) - 1;
    float wheelSlipReL = (wheelSpeeds[2]/vehicleSpeed) - 1;
    float wheelSlipReR = (wheelSpeeds[3]/vehicleSpeed) - 1;
    //check for vehicle speed > 10mph to activate traction control
    if (vehicleSpeed > 4.47){
      slip = max(wheelSlipReL, wheelSlipReR);
    } else {
      slip = 0;
    }
    // check if we have more slip than desired
    if (slip > desiredSlip){
      double error = desiredSlip - slip;
      integral += error * sampleRate;
      double derivative = (error - prevError) / sampleRate;

      throttleOutput = Kp * error + Ki * integral + Kd * derivative;
      throttleOutput = constrain(throttleOutput, 0, 255);
      analogWrite(4, throttleOutput);

      prevError = error;
      prevTime = currTime;
    } else {
      // if slip is not enough, no adjustments made to throttle
      analogWrite(4, 0)
    }
  }
}
