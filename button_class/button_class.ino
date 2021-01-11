/* button_interrupt.ino
 *
 * Count each time a button is pressed
 *
 */

#include <LiquidCrystal.h>

#include "button.hpp"
#define PIN 6
#define DEBOUNCE_DELAY 50

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int clicks = 0;

components::Button button = components::Button(PIN, DEBOUNCE_DELAY, HIGH);

void setup() {
    analogWrite(A3, 0);  // brightness
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print(0);
}

void loop() {
    if (button.isPressed()) {
        lcd.clear();
        lcd.print(++clicks);
    }
}
