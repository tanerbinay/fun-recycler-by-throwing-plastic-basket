#include <LiquidCrystal_I2C.h>
// initialize the lcd library


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int x = 0; // variable for reading the pin status
int input = A0; // choose the input pin (for IR sensor)
int state = 0; // we start, assuming no motion detected

LiquidCrystal_I2C lcd(0x3f, 16, 2); // set the LCD address to 0x3f for a 16 chars and 2 line display

void setup()
{
  lcd.init(); // initialize the lcd

  // Print a message to the LCD.
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Basket counter ");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print("     =Basket  ");
}
void loop()
{
  int counter = digitalRead(A0); // read input value
  if (state == 0)
  {
    switch (counter) {

      case 1 : state = 1; lcd.setCursor (0, 1); x = x + 1; lcd.print(x); break;
      case 0 : state = 0; break;

    }
  }

  if (counter == LOW) {
    state = 0;
  }
}
