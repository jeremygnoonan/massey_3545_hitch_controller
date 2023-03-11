// HitchCalibration.h
#ifndef HitchCalibration_h
#define HitchCalibration_h

#include <Arduino.h>

class HitchCalibration {
  private:    
    uint8_t sensorPin; 
    int averageIndex;
    int lastGoodPosition;
    const int averageCount = 80;
    const int positionCount = 14;
    const int stepsPerInterval = 10;
    int averagedValues[80] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int positionData[14] = {705, 722, 755, 791, 828, 862, 893, 917, 934, 944, 950, 953, 956, 960}; 

  public:
    HitchCalibration(uint8_t pin);
    
    int getPosition();

    void updateAverage();

    int getCurrentAverage();

};

#endif
