#include "Arduino.h"
#include "VehControls-wheelSpeed.h"

const int sensorPins[4] = {50, 51, 52, 53};
volatile unsigned long wheelPulses[4] = {0, 0, 0, 0};
const float wheelCircumference = 2.1258; // circumference in meters
const unsigned long timeInterval = 10; // 100 Hz
unsigned long previousTime = 0;

void wheelSpeedSetup() {
  // Setting up input pins
  // Calling interrupt to count pulses on rising edge to get individual wheel speeds
  for (int i = 0; i < 4; i++) {
        pinMode(sensorPins[i], INPUT);
        attachInterrupt(digitalPinToInterrupt(sensorPins[i]), []() { wheelPulses[i]++; }, RISING);
  }

}

void wheelSpeedCalc(unsigned long wheelSpeeds[4]){
  unsigned long currentTime = millis();
  // check if we have reached the time interval, and calculate wheel speeds
  if (currentTime - previousTime >= timeInterval){
    previousTime = currentTime;
    noInterrupts(); // pause interrupts while counting pulses
    for (int i = 0; i < 4; i++) {
      wheelSpeeds[i] = (wheelPulses[i] * wheelCircumference)/(timeInterval/1000);// gives speed in m/s
      wheelPulses[i] = 0; // reset pulse count
    }
    interrupts(); // resume interrupts
  }
}