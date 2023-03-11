//LCD1602
//You should now see your LCD1602 display the flowing characters "SUNFOUNDER" and "hello, world"
//Email:info@primerobotics.in
//Website:www.primerobotics.in
//2015.5.7 
#include <LiquidCrystal.h>// include the library code
#include "HitchCalibration.h"
/**********************************************************/

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

HitchCalibration hitchCalibration(A5);
/*********************************************************/

int recordedSetHitchHeight = 0;
int recordedSensorHeight = 0;
int loopCount = 0;


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows: 

  lcd.setCursor(0,0);  // set the cursor to column 15, line 0
  lcd.print("Hitch Set: 50%");
  lcd.setCursor(0,1);
  lcd.print("Hitch Cur: 24%");

}
/*********************************************************/
void loop() 
{
  float currenSetHitchHeightFloat  = 100 - (analogRead(A0) / 1023.0 * 100);
  int currenSetHitchHeight = (int)currenSetHitchHeightFloat;

  hitchCalibration.updateAverage();
  int position = hitchCalibration.getPosition();

  recordedSetHitchHeight = currenSetHitchHeight;   

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

  loopCount++;
  

  delay(2);
}
/************************************************************/