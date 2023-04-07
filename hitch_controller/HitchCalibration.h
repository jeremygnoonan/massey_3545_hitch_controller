// HitchCalibration.h
#ifndef HitchCalibration_h
#define HitchCalibration_h

#include <Arduino.h>

class HitchCalibration {
  private:    
    uint8_t sensorPin; 
    int averageIndex;
    int lastGoodPosition;
    const int averageCount = 16;
    const int positionCount = 27;
    const int stepsPerInterval = 5;
    int averagedValues[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int positionData[27] = {685,695,707,724,738,757,772,793,808,826,841,857,869,881,890,899,905,911,915,918,920,922,924,925,927,928,929}; 

  public:
    HitchCalibration(uint8_t pin);
    
    int getPosition();

    void updateAverage();

    int getCurrentAverage();

};

#endif
