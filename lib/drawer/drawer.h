#pragma once

#include <Arduino.h>

#include <Adafruit_SH1106.h>
#include <keyboard.h>

class Drawer
{
public:
    Adafruit_SH1106 display;
    uint8_t frameIndex;

    Drawer();

    void drawFrame(Keyboard& keyboard);
};