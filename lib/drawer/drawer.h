#pragma once

#include <Arduino.h>

#include <Adafruit_SH1106.h>
#include <keyboard.h>

class Drawer
{
private:
    
public:
    uint8_t frameIndex;
    Drawer();

    void drawFrame(Adafruit_SH1106& display, Keyboard& keyboard);
};