#include "Calculator.h"

#include <5x5characters.h>

Calculator::Calculator()
{
    inputField.reserve(50);
}

void Calculator::drawEquation(Adafruit_SH1106& display, String& equation, uint8_t x, uint8_t y)
{
    uint8_t row = x;
    uint8_t col = y;

    for (unsigned int i = 0; i < equation.length(); i++)
    {
        display.drawBitmap(row, col, charToBitmap(equation[i]), 5, 5, WHITE);
        row += 5;

        if (row > 80)
        {
            row = x;
            col += 6;
        }
    }
}

const unsigned char (&Calculator::charToBitmap(char& character))[5]
{
    switch (character)
    {
    case '0': return smallZero;
    case '1': return smallOne;
    case '2': return smallTwo;
    case '3': return smallThree;
    case '4': return smallFour;
    case '5': return smallFive;
    case '6': return smallSix;
    case '7': return smallSeven;
    case '8': return smallEight;
    case '9': return smallNine;

    case '.': return smallPoint;
    case '+': return smallAdd;
    case '-': return smallSubtract;
    case '*': return smallMultiply;
    case '/': return smallDivide;
    case '=': return smallEqual;

    case '(': return smallLeftBracket;
    case ')': return smallRightBracket;

    default:
        return smallSwapArrow;
    }
}