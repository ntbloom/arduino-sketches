#ifndef BUTTON_HPP
#define BUTTON_HPP

// symlink from appropriate location
// possibly $HOME/.arduino15/packages/arduino/hardware/samd/x.y.z
#include "cores/arduino/api/ArduinoAPI.h"

/* basic class for controlling and debouncing buttons */
class Button {
   private:
    int m_pin;
    unsigned long m_msDelay;
    unsigned long m_lastDebounce;
    bool m_high;
    bool m_read = LOW;

   public:
    Button(int pin, unsigned long msDelay, bool high) {
        m_pin = pin;
        m_msDelay = msDelay;
        m_high = high;

        m_lastDebounce = 0;
        pinMode(m_pin, INPUT);
    };
    bool isPressed();
};

#endif
