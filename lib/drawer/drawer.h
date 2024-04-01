#pragma once

#include <Arduino.h>

#include <Adafruit_SH1106.h>
#include <Keyboard.h>
#include <Menu.h>
#include <Calculator.h>

#include <DataTypes.h>

class Drawer
{
public:
    Adafruit_SH1106 display;
    uint8_t frameIndex;

    Drawer();

    void drawFrame(Mode& mode, Keyboard& keyboard, Menu& menu, Calculator& calculator);
};