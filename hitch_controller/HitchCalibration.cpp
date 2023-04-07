// HitchCalibration.cpp
#include "HitchCalibration.h"

HitchCalibration::HitchCalibration(uint8_t pin) {
  averageIndex = 0;
  lastGoodPosition = -1;
  sensorPin = pin;
  pinMode(sensorPin, INPUT);
}

//fix missing value bug
int HitchCalibration::getPosition() {
  int position = 0;
  int currentAverage = getCurrentAverage();
  
  //Serial.println(currentAverage);
  for(int i = 0; i < positionCount -1; i++){
    
    int lower = positionData[i];
    int upper = positionData[i + 1];

    if(currentAverage >= upper){
      continue;
    }

    int interval = map(currentAverage, upper, lower, stepsPerInterval, 1);

    if(interval < 0){
      interval = 0;
    }

    return ((positionCount - 1) * stepsPerInterval) - (i * stepsPerInterval) - interval - (stepsPerInterval * 6);
  }

  return -1;
}

void HitchCalibration::updateAverage() {

  averagedValues[averageIndex] = analogRead(sensorPin);
  averageIndex++;
  if(averageIndex == averageCount){
    averageIndex = 0;
  }
}

int HitchCalibration::getCurrentAverage(){
  long average = 0;

  for(int i = 0; i < averageCount; i++){
    average += averagedValues[i];
  }

  average = average / averageCount;

  return average;
}