/* button_interrupt.ino
 *
 * Count each time a button is pressed
 *
 */

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int PIN = 6;
int clicks = 0;
unsigned long debounce_delay = 50;
unsigned long last_debounce = 0;

void setup() {
  analogWrite(A3, 0);  // brightness
  lcd.begin(16, 2);
  pinMode(PIN, INPUT);
}

void loop() {
  int value = digitalRead(PIN);
  if (value) {
    // button is pressed, is it valid or not?
    if ((millis() - last_debounce) > debounce_delay) {
      clicks++;
      lcd.clear();
      lcd.print(clicks);
    }
    last_debounce = millis();
  }
  int result = clicks;
}
