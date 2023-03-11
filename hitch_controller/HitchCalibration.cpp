// HitchCalibration.cpp
#include "HitchCalibration.h"

HitchCalibration::HitchCalibration(uint8_t pin) {
  averageIndex = 0;
  sensorPin = pin;
  pinMode(sensorPin, INPUT);
}

//fix missing value bug
int HitchCalibration::getPosition() {
  int position = 0;
  
  for(int i = 0; i < positionCount; i++){
    if(positionData[i] == getCurrentAverage()){
      return positionCount - i;
    }
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
  int average = 0;

  for(int i = 0; i < averageCount; i++){
    average += averagedValues[i];
  }

  average = average / averageCount;

  return average;
}