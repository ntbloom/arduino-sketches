/* button_interrupt.ino
 *
 * Debugging why we don't get single counts on each button press
 *
 */

volatile int PIN = 6;
volatile int clicks;

/* count clicks */
void count() {
  clicks++;
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN, INPUT_PULLUP);
  attachInterrupt(PIN, count, FALLING);
}

void loop() {
  noInterrupts();
  Serial.println(clicks);
  interrupts();

}
