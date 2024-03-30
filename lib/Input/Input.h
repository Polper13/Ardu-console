#pragma once

#include <Arduino.h>

// button pins
#define E 2
#define D 3
#define W 4
#define S 5
#define A 6
#define Q 7

class Input
{
private:
    uint8_t lastButtonStates[6];
    bool* pressedDownVariablesPtr[6] = 
    {
        &ePressedDown,
        &dPressedDown,
        &wPressedDown,
        &sPressedDown,
        &aPressedDown,
        &qPressedDown,
    };

public:
    bool wPressedDown;
    bool aPressedDown;
    bool sPressedDown;
    bool dPressedDown;
    bool ePressedDown;
    bool qPressedDown;

    Input();

    void update();
};