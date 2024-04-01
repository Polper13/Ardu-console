#include "Keyboard.h"
#include "5x5characters.h"
#include "CustomCharacters.h"

Keyboard::Keyboard()

{
    cursorX = 0;
    cursorY = 0;
}

void Keyboard::drawKeyboard(Adafruit_SH1106& display)
{
    // arrow part
    display.drawFastHLine(95, 47, 33, WHITE);
    display.drawFastHLine(95, 63, 33, WHITE);
    display.drawFastHLine(95, 55, 25, WHITE);

    display.drawFastVLine(95, 47, 17, WHITE);
    display.drawFastVLine(103, 47, 17, WHITE);
    display.drawFastVLine(111, 47, 17, WHITE);
    display.drawFastVLine(119, 47, 17, WHITE);
    display.drawFastVLine(127, 47, 17, WHITE);

    // num part
    display.drawFastHLine(95, 13, 33, WHITE);
    display.drawFastHLine(95, 21, 33, WHITE);
    display.drawFastHLine(95, 29, 33, WHITE);
    display.drawFastHLine(95, 37, 33, WHITE);
    display.drawFastHLine(95, 45, 33, WHITE);

    display.drawFastVLine(95, 13, 33, WHITE);
    display.drawFastVLine(103, 13, 33, WHITE);
    display.drawFastVLine(111, 13, 33, WHITE);
    display.drawFastVLine(119, 13, 33, WHITE);
    display.drawFastVLine(127, 13, 33, WHITE);

    // characters
    // arrow part
    display.drawBitmap(97, 49, smallLeftBracket, 5, 5, WHITE);
    display.drawBitmap(105, 49, smallUpArrow, 5, 5, WHITE);
    display.drawBitmap(113, 49, smallRightBracket, 5, 5, WHITE);

    display.drawBitmap(97, 57, smallLeftArrow, 5, 5, WHITE);
    display.drawBitmap(105, 57, smallDownArrow, 5, 5, WHITE);
    display.drawBitmap(113, 57, smallRightArrow, 5, 5, WHITE);

    display.drawBitmap(121, 53, smallEqual, 5, 5, WHITE);

    // num part
    display.drawBitmap(97, 15, smallSeven, 5, 5, WHITE);
    display.drawBitmap(105, 15, smallEight, 5, 5, WHITE);
    display.drawBitmap(113, 15, smallNine, 5, 5, WHITE);
    display.drawBitmap(121, 15, smallDivide, 5, 5, WHITE);

    display.drawBitmap(97, 23, smallFour, 5, 5, WHITE);
    display.drawBitmap(105, 23, smallFive, 5, 5, WHITE);
    display.drawBitmap(113, 23, smallSix, 5, 5, WHITE);
    display.drawBitmap(121, 23, smallMultiply, 5, 5, WHITE);

    display.drawBitmap(97, 31, smallOne, 5, 5, WHITE);
    display.drawBitmap(105, 31, smallTwo, 5, 5, WHITE);
    display.drawBitmap(113, 31, smallThree, 5, 5, WHITE);
    display.drawBitmap(121, 31, smallSubtract, 5, 5, WHITE);

    display.drawBitmap(97, 39, smallZero, 5, 5, WHITE);
    display.drawBitmap(105, 39, smallPoint, 5, 5, WHITE);
    display.drawBitmap(113, 39, smallSwapArrow, 5, 5, WHITE);
    display.drawBitmap(121, 39, smallAdd, 5, 5, WHITE);
}

void Keyboard::drawCursor(Adafruit_SH1106& display, uint8_t frameIndex)
{
    if (frameIndex <= 3)
    {
        uint8_t xCalculated = cursorX * 8 + 96;
        uint8_t yCalculated = cursorY * 8;
        
        if (cursorY <= 3)
            yCalculated += 14;
        else
            yCalculated += 16;

        // if cursor is on '='
        if (cursorX == 3 && cursorY >= 4)
        {
            display.drawBitmap(120, 52, cursorSymbol, 7, 7, WHITE);
            return;
        }
        
        display.drawBitmap(xCalculated, yCalculated, cursorSymbol, 7, 7, WHITE);
    } 
}

void Keyboard::update(Input& input)
{
    if (input.ePressedDown)
    {
        // select smth
    }
    if (input.wPressedDown)
    {
        if (cursorY > 0)
            cursorY--;
    }
    if (input.sPressedDown)
    {
        if (cursorY < 5)
            cursorY++;
    }
    if (input.dPressedDown)
    {
        if (cursorX < 3)
            cursorX++;
    }
    if (input.aPressedDown)
    {
        if (cursorX > 0)
            cursorX--;
    }
}