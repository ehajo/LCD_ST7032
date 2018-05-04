//-------------------------------------------------------------------------------------------
// Tested Module    : eHaJo COG-Display
// Drive IC         : ST7032
// INTERFACE        : I2C
// VDD              : 3.3V-5.0V
// Tested with MCU	: Arduino Uno, Atmega328P-PU
//-------------------------------------------------------------------------------------------

#include <LCD_ST7032.h>

LCD_ST7032 lcd;

void setup() {  
  lcd.begin(DISPLAY_5V, DISPLAY_2LINE); // DISPLAY_5V or DISPLAY_3V | DISPLAY_2LINE or DISPLAY_1LINE
  lcd.setcontrast(8); //contrast value range is 0-63, try 8@5V or 30@3.3V as a starting value
  
  // Write a piece of text on the first line...
  lcd.setCursor(0, 0);  //LINE 1, ADDRESS 0
  lcd.print("eHaJo.de");

  // Write a piece of text on the second line...
  lcd.setCursor(1, 0);
  lcd.print("COG-Display");
}

void loop() {
  lcd.display();
  delay(1000);
  lcd.noDisplay();
  delay(250);
}