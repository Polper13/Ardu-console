#include "Calculator.h"

#include <5x5characters.h>

Calculator::Calculator()
{
    inputField.reserve(50);
}

void Calculator::drawEquation(Adafruit_SH1106& display, String& equation)
{
    const uint8_t rowLength = 16;
    const uint8_t charWidth = 5;
    const uint8_t rowHeight = 8;

    const uint8_t startingX = 4;
    const uint8_t startingY = 4;

    uint8_t length = equation.length();
    uint8_t drawStartIndex = 0;
    uint8_t drawEndIndex = 0;
    uint8_t rowSelected = 0;

    while (true)
    {
        if (length - drawEndIndex > rowLength) // check how much text is left to display
        {
            drawEndIndex += rowLength - 1; // mark next characters to be draw

            for (uint8_t i = drawEndIndex; i > 0; i--) // unmark "cutinhalf" numbers
            {
                char nextChar = equation[i + 1];

                if (evaluateOperation(nextChar) != 0 && evaluateOperation(nextChar) != 3) // if next character is +, -, * or /
                {
                    drawEndIndex = i; // set final marker for selection end
                    break;
                }

                if (i == drawStartIndex) // hasnt fit single number even in new empty line
                    break; // cut it in half and draw anyway
            }
        }

        else // if less than one full line of text is left
            drawEndIndex = length - 1; // mark rest of the text to be drawn

        for (int i = drawStartIndex; i <= drawEndIndex; i++) // draw marked characters as bitmaps
        {
            char currentCharacter = equation[i];

            const unsigned char (&accordingBitmap)[5] = charToBitmap(currentCharacter); // reference to bitmap of currently selected character
            uint8_t x = startingX + (i - drawStartIndex) * charWidth; // starting x coord + (index in currently drawn row) * character spacing
            uint8_t y = startingY + rowSelected * rowHeight;

            display.drawBitmap(x, y, accordingBitmap, 5, 5, WHITE);
        }

        if (drawEndIndex != length - 1) // hasnt ended drawing whole text
        {
            drawStartIndex = drawEndIndex + 1;
            rowSelected++;
        }
        else // if ended drawing whole text break loop and end func
        {
            break;
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
    case '^': return smallPower;
    case '=': return smallEqual;

    case '(': return smallLeftBracket;
    case ')': return smallRightBracket;

    default:
        return smallSwapArrow;
    }
}

uint8_t Calculator::evaluateOperation(char operationSymbol)
{
    switch (operationSymbol)
    {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    
    default:
        return 0;
    }
}