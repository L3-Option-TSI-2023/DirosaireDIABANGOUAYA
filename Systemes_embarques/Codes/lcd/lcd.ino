#include <LiquidCrystal.h>

const int rs = 40, en = 30, d4 = 32, d5 = 34, d6 = 36, d7 = 38;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  //pinMode(rs, INPUT);
  lcd.begin(16,2);
  lcd.print("vive le Maroc");
  lcd.setCursor(0, 1);
  lcd.print("we are the best");

}

void loop() 
{
 
}
