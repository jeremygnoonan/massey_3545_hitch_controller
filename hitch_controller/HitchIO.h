// HitchIO.h
#ifndef HitchIO_h
#define HitchIO_h

#include <Arduino.h>

class HitchIO {
  private:    
    int hitchSwitchUpPin; 
    int hitchSwitchDownPin; 
    int hitchRelayUpPin; 
    int hitchRelayDownPin; 
    int hitchSettingPin; 
    int hitchSetting;
    int currentPosition;
    bool movingDown;

  public:
    HitchIO(int hSwitchUpPin, int hSwitchDownPin, int hRelayUpPin, int hRelayDownPin, int hSettingPin);
    
    void setupPins();
    
    void moveHitchToPosition(int position);

    void moveHitchUp();

    void stop();

    bool downPressed();

    bool upPressed();

    void setHitchSetting(int setting);

    void setCurrentPosition(int position);

    bool isMovingDown();

};

#endif
