/* button_interrupt.ino
 *
 * Count each time a button is pressed
 *
 */

#include <LiquidCrystal.h>
#define PIN 6
#define DEBOUNCE_DELAY 50

const int rs = 12, en = 11, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int clicks = 0;

/* basic class for controlling and debouncing buttons */
class Button {
   private:
    int m_pin;
    unsigned long m_msDelay;
    unsigned long m_lastDebounce;
    bool m_high;
    bool m_read;
    bool m_pressed;

   public:
    Button(int pin, unsigned long msDelay, bool high) {
        m_pin = pin;
        m_msDelay = msDelay;
        m_lastDebounce = 0;
        pinMode(m_pin, INPUT);
    }

    /* is the button pressed and valid (not bouncing) */
    bool isPressed() {
        m_read = digitalRead(m_pin);

        // check if pin fired
        switch (m_high) {
            case HIGH:
                if (!m_read) {
                    return false;
                }
            case LOW:
                if (m_read) {
                    return false;
                }
        }

        // debounce it
        bool b = false;
        if ((millis() - m_lastDebounce) > m_msDelay) {
            b = true;
        }
        m_lastDebounce = millis();
        return b;
    };
};

Button button = Button(PIN, DEBOUNCE_DELAY, HIGH);

void setup() {
    analogWrite(A3, 0);  // brightness
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print(0);
}

void loop() {
    if (button.isPressed()) {
        clicks++;
        lcd.clear();
        lcd.print(clicks);
    }
}
