#pragma once

#include <Arduino.h>
#include <Adafruit_SH1106.h>
#include <Input.h>

#include <dataTypes.h>

#define Epin 2
#define Dpin 3
#define Wpin 4
#define Spin 5
#define Apin 6
#define Qpin 7

class Menu
{
private:
    const char *menuButtons[4] = // to change menu change table and switch in update func
    {
        "Calculator",
        "Messenger",
        "Math solver",
        "Notes"
    };

    const uint8_t lastButtonIndex = 3;
    uint8_t selectionIndex;

public:
    Menu();

    void drawMenu(Adafruit_SH1106& display);
    void update(Input& input, Mode& mode);
};