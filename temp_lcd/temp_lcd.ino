/* temp_lcd.ino
 *
 * Prototype for printing temperature data on a 16x2 LCD screen
 *
 */

#include <LiquidCrystal.h>

#define RS 12
#define EN 11
#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define BRIGHT_PIN 18  // marked as A3
#define BRIGHTNESS 0
#define TEMP_PIN 16  // marked as A1
#define TEMP_VOLTAGE 3.3
#define TEMP_UNIT 'F'

LiquidCrystal LCD(RS, EN, D4, D5, D6, D7);
String TEMP_STR;
int TEMP_VAL;

/* read temperature from TMP36 sensor
 * specify analog pin, voltage, and unit 'F' or 'C'
 */
int get_temp(int pin, float voltage, char unit) {
  int reading = analogRead(pin);
  float intermed = reading * voltage / 1024;
  float temp_c = (intermed - 0.5) * 100;  // 10mv per degree with 500 mV offset
  float temp_f = (temp_c * 9.0 / 5.0) + 32.0;
  switch (unit) {
    case 'F':
      return (int)temp_f;
    case 'C':
      return (int)temp_c;
    default:
      return -99;
  }
}

/* convert temp to string */
String temp_to_str(int temp, char unit) {
  String s, t;

  if (temp > 0) {
    t = "+" + String(temp);
  } else if (temp == 0) {
    t = " " + String(temp);
  } else {
    t = String(temp);
  }

  switch (unit) {
    case 'F':
      s = t + "F";
      break;
    case 'C':
      s = t + "C";
      break;
    default:
      s = t + "?";
  }
  return s;
}

void setup() {
  analogWrite(BRIGHT_PIN, BRIGHTNESS);  // set the brightness
  LCD.begin(16, 2);
}

void loop() {
  LCD.clear();
  TEMP_VAL = get_temp(TEMP_PIN, TEMP_VOLTAGE, TEMP_UNIT);
  TEMP_STR = temp_to_str(TEMP_VAL, TEMP_UNIT);
  LCD.print(TEMP_STR);
  delay(1000);
}
