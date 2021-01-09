#include <LiquidCrystal.h>

/* Prototype for printing weather data on a 16x2 LCD screen
 *
 */

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  /* prototyping how the LCD screen might look */
  analogWrite(A3, 0);  // brightness, 0-255
  lcd.begin(16, 2);
  // lcd.print("10.25\" since");
  // lcd.setCursor(0, 1);
  // lcd.print("12/31 14:21  90F");
  Serial.begin(9600);
}
int count = 0;
int incoming_byte = 1;

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(count++);
  if (Serial.available() > 0) {
    incoming_byte = Serial.read();
    if (incoming_byte != 0) {
      lcd.setCursor(count++, 0);
      lcd.print(String((char)incoming_byte));
    } else {
      count = 0;
      lcd.print("Cleared    ");
      lcd.clear();
    }
  }
  delay(100);
}
