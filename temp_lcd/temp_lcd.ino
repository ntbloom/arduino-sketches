#include <LiquidCrystal.h>

/* Prototype for printing temperature data on a 16x2 LCD screen
 *
 */

#define RS 12
#define EN 11
#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define TEMP_PIN A1
#define TEMP_VOLTAGE 3.3
#define TEMP_UNIT 'F'

LiquidCrystal LCD(RS, EN, D4, D5, D6, D7);

/* read temperature from TMP36 sensor using +3.3v on pin A1 */
int get_temp(int pin, float voltage) {
  int reading = analogRead(pin);
  float intermed = reading * voltage / 1024;
  float temp_c = (intermed - 0.5) * 100;  // 10mv per degree with 500 mV offset
  int temp_f = (int)(temp_c * 9.0 / 5.0) + 32.0;
  return temp_f;
}

/* write the temperature to the LCD, specify 'F' or 'C' */
void write_temp(int temp, char unit) {
  String s;
  switch (unit) {
    case 'F':
      s = "F";
      break;
    case 'C':
      s = "C";
      break;
    default:
      s = "?";
  }
  LCD.print(temp + s);
}

void setup() {
  analogWrite(A3, 0);  // set the brightness
  LCD.begin(16, 2);
}

void loop() {
  LCD.clear();
  int temp = get_temp(TEMP_PIN, TEMP_VOLTAGE);
  write_temp(temp, TEMP_UNIT);
  delay(5000);
}
