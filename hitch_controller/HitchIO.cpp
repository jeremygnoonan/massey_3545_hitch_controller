// HitchCalibration.cpp
#include "HitchIO.h"
#include "Arduino.h"

HitchIO::HitchIO(int hSwitchUpPin, int hSwitchDownPin, int hRelayUpPin, int hRelayDownPin, int hSettingPin) {
    hitchSwitchUpPin = hSwitchUpPin;
    hitchSwitchDownPin = hSwitchDownPin;
    hitchRelayUpPin = hRelayUpPin;
    hitchRelayDownPin = hRelayDownPin;
    hitchSettingPin = hSettingPin;

    
}

void HitchIO::setupPins(){
    pinMode(hitchRelayDownPin, OUTPUT);
    pinMode(hitchRelayUpPin, OUTPUT);
    pinMode(hitchSwitchDownPin, INPUT);
    pinMode(hitchSwitchUpPin, INPUT);
}

void HitchIO::moveHitchToPosition(int position){
    if(currentPosition > hitchSetting){
        movingDown = true;
        digitalWrite(hitchRelayUpPin, LOW);
        digitalWrite(hitchRelayDownPin, HIGH);
    }
    else{
        movingDown = false;
        digitalWrite(hitchRelayUpPin, LOW);
        digitalWrite(hitchRelayDownPin, LOW);
    }
}

void HitchIO::moveHitchUp(){
    digitalWrite(hitchRelayDownPin, LOW);
    digitalWrite(hitchRelayUpPin, HIGH);
}

bool HitchIO::downPressed(){
    return digitalRead(hitchSwitchDownPin) == LOW;
}

bool HitchIO::upPressed(){
    return digitalRead(hitchSwitchUpPin) == LOW;
}

void HitchIO::setHitchSetting(int setting){
    hitchSetting = setting;
}

void HitchIO::setCurrentPosition(int position){
    currentPosition = position;
}

void HitchIO::stop(){
    digitalWrite(hitchRelayUpPin, LOW);
    digitalWrite(hitchRelayDownPin, LOW);
}

bool HitchIO::isMovingDown(){
    return movingDown;
}