#pragma once

#include <Adafruit_SH1106.h>
#include <Drawer.h>
#include <keyboard.h>
#include <Menu.h>
#include <Input.h>

class Engine
{
private:
    unsigned long previousMillis; 
    const unsigned long interval;

public:
    Drawer drawer;
    Keyboard keyboard;
    Menu menu;
    Input input;

    Engine(uint8_t targetUpdateRate);

    void checkForUpdates();
};