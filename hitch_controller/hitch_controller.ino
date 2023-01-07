//LCD1602
//You should now see your LCD1602 display the flowing characters "SUNFOUNDER" and "hello, world"
//Email:info@primerobotics.in
//Website:www.primerobotics.in
//2015.5.7 
#include <LiquidCrystal.h>// include the library code
/**********************************************************/
char array1[]="Hi Shawn";  //the string to print on the LCD
char array2[]="You look nice 8====D ";  //the string to print on the LCD
int tim = 250;  //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
/*********************************************************/

int recordedHitchHeight = 0;

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


  float currentHitchHeightFloat  = 100 - (analogRead(A5) / 1023.0 * 100);
  int currentHitchHeight = (int)currentHitchHeightFloat;
  if(currentHitchHeight != recordedHitchHeight){
    recordedHitchHeight = currentHitchHeight;   

    lcd.clear();
    lcd.setCursor(0,0);  // set the cursor to column 15, line 0
    lcd.print("Hitch Set: ");
    lcd.print(currentHitchHeight);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Hitch Cur: 24%");
  }

  delay(50);
}
/************************************************************/