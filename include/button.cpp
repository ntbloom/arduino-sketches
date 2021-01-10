#include "button.hpp"

/* is the button pressed and valid (not bouncing) */
bool Button::isPressed() {
    // check if pin fired
    m_read = digitalRead(m_pin);
    switch (m_high) {
        case HIGH:
            if (!m_read) {
                return false;
            }
            break;
        case LOW:
            if (m_read) {
                return false;
            }
            break;
    }

    // debounce it
    bool b = false;
    if ((millis() - m_lastDebounce) > m_msDelay) {
        b = true;
    }
    m_lastDebounce = millis();
    return b;
}
