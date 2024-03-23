#pragma once

#include <Adafruit_SH1106.h>
#include <keyboard.h>

class Drawer
{
private:
    unsigned long previousMillis; 
    const unsigned long interval;

    Adafruit_SH1106 display;
    Keyboard keyboard;

public:
    uint8_t frameIndex;
    Drawer(uint8_t targetFPS);

    void drawFrame();
    void checkForDraws();
};