//LCD1602
//You should now see your LCD1602 display the flowing characters "SUNFOUNDER" and "hello, world"
//Email:info@primerobotics.in
//Website:www.primerobotics.in
//2015.5.7 
#include <LiquidCrystal.h>// include the library code
/**********************************************************/

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
/*********************************************************/

int recordedSetHitchHeight = 0;
int recordedSensorHeight = 0;

int averagedReadings[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int readingCount = 0;

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

  averagedReadings[readingCount] = analogRead(A5);
  readingCount++;
  if(readingCount == 80){
    readingCount = 0;
  }

  int pAverage = 0;

  for(int i = 0; i < 80; i++){
    pAverage += averagedReadings[i];
  }

  pAverage = pAverage / 80;

  Serial.print("Prenus ");
  Serial.println(pAverage);
  
  if(abs(currenSetHitchHeight-recordedSetHitchHeight) >2){
    recordedSetHitchHeight = currenSetHitchHeight;   

    lcd.clear();
    lcd.setCursor(0,0);  // set the cursor to column 15, line 0
    lcd.print("Hitch Set: ");
    lcd.print(currenSetHitchHeight);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Hitch Cur: 24%");
  }

  delay(2);
}
/************************************************************/