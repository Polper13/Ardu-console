#pragma once

#include <Adafruit_SH1106.h>

#define Epin 2
#define Dpin 3
#define Wpin 4
#define Spin 5
#define Apin 6
#define Qpin 7

class Keyboard
{
private:
    unsigned char cursorX;
    unsigned char cursorY;

    unsigned char lastStateW;
    unsigned char lastStateA;
    unsigned char lastStateS;
    unsigned char lastStateD;
    unsigned char lastStateE;
    unsigned char lastStateQ;

    const unsigned char keyboardLayout[24] =
    {
        '7', '8', '9', '/',
        '4', '5', '6', '*',
        '1', '2', '3', '-',
        '0', '.', 's', '+',
        
        '(', 'u', ')', '=',
        'l', 'd', 'r', '=',
    };

    void buttonEPressed();
    void buttonDPressed();
    void buttonWPressed();
    void buttonSPressed();
    void buttonAPressed();
    void buttonQPressed();

public:
    Keyboard();

    void drawKeyboard(Adafruit_SH1106& display);
    void drawCursor(Adafruit_SH1106& display, uint8_t frameIndex);
    void handleInput();
};