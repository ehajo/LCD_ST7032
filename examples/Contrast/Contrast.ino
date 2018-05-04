//-------------------------------------------------------------------------------------------
// Tested Module    : eHaJo COG-Display
// Drive IC         : ST7032
// INTERFACE        : I2C
// VDD              : 3.3V-5.0V
// Tested with MCU	: Arduino Uno, Atmega328P-PU
//-------------------------------------------------------------------------------------------

#include <LCD_ST7032.h>

LCD_ST7032 lcd;

const byte contrastButtonPin = 3;
boolean lastButtonState = 1;

void setup() {
  pinMode(contrastButtonPin, INPUT);
  digitalWrite(contrastButtonPin, HIGH);
  lcd.begin(DISPLAY_5V, DISPLAY_2LINE); // DISPLAY_5V or DISPLAY_3V | DISPLAY_2LINE or DISPLAY_1LINE
  lcd.setcontrast(8); //contrast value range is 0-63, try 8@5V or 30@3.3V as a starting value
}

void loop() {
  boolean a = digitalRead(contrastButtonPin);
  if (a != lastButtonState) {
    if (!a) {
      lcd.adjcontrast(1); //increase contrast (-1 to decrease)
    }
    lastButtonState = a;
  }

  lcd.setCursor(0, 0);  //LINE 1 ADDRESS 0
  lcd.print("Contrast value:");
  lcd.setCursor(1, 0);  //LINE 2 ADDRESS 0
  byte c = lcd.getcontrast();
  lcd.print(c, DEC);
  lcd.write(' ');

}
