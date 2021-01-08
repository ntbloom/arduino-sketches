/* rain_lcd.ino
 *
 * Prototype for counting rain gauge clicks and printing them on screen
 *
 */

//#include <LiquidCrystal.h>

#define RS 12
#define EN 11
#define D4 2
#define D5 3
#define D6 4
#define D7 5
#define BRIGHT_PIN 18  // marked as A3
#define BRIGHTNESS 0
#define RAIN_PIN 6
#define UNIT "standard"
#define GAUGE_IN 0.11
#define GAUGE_MM 0.2794

// LiquidCrystal LCD(RS, EN, D4, D5, D6, D7);
static float total_rain;
volatile int clicks;
static int rain_state;

/* add more clicks to the gauge */
void count() {
  clicks++;
  // LCD.clear();
  // LCD.print(clicks);
}

void setup() {
  // analogWrite(BRIGHT_PIN, BRIGHTNESS);  // set the brightness
  // LCD.begin(16, 2);
  Serial.begin(9600);
  pinMode(RAIN_PIN, INPUT);
  attachInterrupt(RAIN_PIN, count, RISING);
}

void loop() {
  // LCD.clear();
  // LCD.print(total_rain);

  // LCD.setCursor(0, 1);
  // rain_state = digitalRead(RAIN_PIN);
  // LCD.print(clicks);
  
  noInterrupts();
  int result = clicks;
  Serial.println(result);
  interrupts();
  delay(1000);
}
