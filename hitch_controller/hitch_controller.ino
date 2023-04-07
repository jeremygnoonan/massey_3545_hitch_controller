//LCD1602
//You should now see your LCD1602 display the flowing characters "SUNFOUNDER" and "hello, world"
//Email:info@primerobotics.in
//Website:www.primerobotics.in
//2015.5.7 


#include "HitchCalibration.h"
#include "HitchIO.h"
#include "Adafruit_LiquidCrystal.h"

#define HITCH_RELAY_DOWN 7
#define HITCH_RELAY_UP 6
#define HITCH_SWITCH_DOWN 10
#define HITCH_SWITCH_UP 11
#define SWITCHED LOW

/**********************************************************/

// initialize the library with the numbers of the interface pins


HitchCalibration hitchCalibration(A0);
HitchIO hitchIO(HITCH_SWITCH_UP, HITCH_SWITCH_DOWN, HITCH_RELAY_UP, HITCH_RELAY_DOWN, A1);

Adafruit_LiquidCrystal lcd(0);
/*********************************************************/

int recordedSetHitchHeight = 0;
int recordedSensorHeight = 0;
int loopCount = 0;
int prevPos = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("GOODAY"); 

  hitchIO.setupPins();  

  if (!lcd.begin(16, 2)) {
    Serial.println("Could not init backpack. Check wiring.");
  }
 
  lcd.setCursor(0,0);  // set the cursor to column 15, line 0
  lcd.print("Hitch Set: 50%");
  lcd.setCursor(0,1);
  lcd.print("Hitch Cur: 24%");

}
/*********************************************************/
void loop() 
{

      lcd.setBacklight(HIGH);
      float currenSetHitchHeightFloat  = analogRead(A1) / 1023.0 * 100;
      int currenSetHitchHeight = (int)currenSetHitchHeightFloat;
      recordedSetHitchHeight = currenSetHitchHeight;   

      hitchIO.setHitchSetting(currenSetHitchHeight);
      hitchCalibration.updateAverage();

      int position = hitchCalibration.getPosition();
      hitchIO.setCurrentPosition(position);

      if(loopCount % 125 == 0){
        lcd.clear();
        lcd.setCursor(0,0);  // set the cursor to column 15, line 0
        lcd.print("Hitch Set: ");
        lcd.print(currenSetHitchHeight);
        lcd.print("%");


        lcd.setCursor(0,1);
        lcd.print("Hitch Cur: ");
        lcd.print(position);    
        loopCount = 0; 
      }

      if(hitchIO.downPressed() || hitchIO.isMovingDown()){
        hitchIO.moveHitchToPosition(currenSetHitchHeight);
      }
      else if(hitchIO.upPressed()){
        hitchIO.moveHitchUp();
      }
      else{
        hitchIO.stop();
      }

      loopCount++;
}