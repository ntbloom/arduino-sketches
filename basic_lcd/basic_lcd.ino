#include <LiquidCrystal.h>

/* Prototype for printing weather data on a 16x2 LCD screen
 *
 */

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* prototyping what a weather printout might look like */
void printWeather() {
    lcd.clear();
    lcd.print("10.25\" since");
    lcd.setCursor(0, 1);
    lcd.print("12/31 14:21  90F");
}

void getSizeof() {
    // lcd.print(sizeof(HIGH));
    unsigned char c = 'a';
    bool b = HIGH;
    float f = 1.0;
    lcd.print(sizeof(f));
}

void setup() {
    /* prototyping how the LCD screen might look */
    analogWrite(A3, 0);  // brightness
    lcd.begin(16, 2);
    // getSizeof();
    unsigned long big = 100;
    unsigned long small = 1;
    lcd.print(small - big);
    // printWeather();
}

void loop() {
    // put your main code here, to run repeatedly:
}
