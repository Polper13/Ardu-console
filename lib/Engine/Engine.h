#pragma once

#include <Adafruit_SH1106.h>
#include <Drawer.h>
#include <keyboard.h>

class Engine
{
private:
    unsigned long previousMillis; 
    const unsigned long interval;

public:
    Adafruit_SH1106 display;
    Drawer drawer;
    Keyboard keyboard;

    Engine(uint8_t targetUpdateRate);

    void checkForUpdates();
};