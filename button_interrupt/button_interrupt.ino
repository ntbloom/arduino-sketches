/* button_interrupt.ino
 *
 * Debugging why we don't get single counts on each button press
 *
 */

volatile int PIN = 5;
volatile int clicks;
unsigned long debounce_delay = 100;
unsigned long last_debounce = 0;

/* count clicks */
void count() {
  if ((millis() - last_debounce) < debounce_delay) {
    clicks++;
  }
  last_debounce = millis();
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN, INPUT_PULLUP);
  attachInterrupt(PIN, count, FALLING);
}

void loop() {
  noInterrupts();
  int result = clicks;
  interrupts();

  Serial.println(result);
}
