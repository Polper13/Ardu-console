#pragma once

#include <Arduino.h>
#include <Adafruit_SH1106.h>

class Menu
{
private:
    const char *menuButtons[4] =
    {
        "Calculator",
        "Messenger",
        "Math solver",
        "Twoj stary"
    };

    const uint8_t lastButtonIndex = 3;
    uint8_t selectionIndex;

public:
    Menu();

    void drawMenu(Adafruit_SH1106& display);
};