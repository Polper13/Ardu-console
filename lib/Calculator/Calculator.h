#pragma once

#include <Arduino.h>
#include <Adafruit_SH1106.h>

class Calculator
{
private:
    String inputField;

public:
    Calculator();

    void drawEquation(Adafruit_SH1106& display, String& equation, uint8_t x, uint8_t y);
    const unsigned char (&charToBitmap(char& character))[5];
};