#include "keyboard.h"
#include "5x5characters.h"
#include "customCharacters.h"
#include <Adafruit_SH1106.h>


void Keyboard::drawCursor(Adafruit_SH1106& display, uint8_t frameIndex)
{
    if (frameIndex <= 3)
    {
        uint8_t xCalculated = cursorX * 9 + 96;
        uint8_t yCalculated = cursorY * 9;
        
        if (cursorY <= 3)
            yCalculated += 14;
        else
            yCalculated += 16;

        display.drawBitmap(xCalculated, yCalculated, cursorSymbol, 7, 7, WHITE);
    }

    
}

void Keyboard::buttonEPressed()
{
    Serial.println("e pressed");
}

void Keyboard::buttonDPressed()
{
    Serial.println("d pressed");
}

void Keyboard::buttonWPressed()
{
    Serial.println("w pressed");
}

void Keyboard::buttonSPressed()
{
    Serial.println("s pressed");
}

void Keyboard::buttonAPressed()
{
    Serial.println("a pressed");
}

void Keyboard::buttonQPressed()
{
    Serial.println("q pressed");
}

void Keyboard::handleInput()
{
    if (digitalRead(Epin) == LOW)
    {
        if (digitalRead(Epin) != lastStateE) { buttonEPressed(); }
        lastStateE = LOW;
    }
    else { lastStateE = HIGH; }

    if (digitalRead(Dpin) == LOW)
    {
        if (digitalRead(Dpin) != lastStateD) { buttonDPressed(); }
        lastStateD = LOW;
    }
    else { lastStateD = HIGH; }

    if (digitalRead(Wpin) == LOW)
    {
        if (digitalRead(Wpin) != lastStateW) { buttonWPressed(); }
        lastStateW = LOW;
    }
    else { lastStateW = HIGH; }

    if (digitalRead(Spin) == LOW)
    {
        if (digitalRead(Spin) != lastStateS) { buttonSPressed(); }
        lastStateS = LOW;
    }
    else { lastStateS = HIGH; }

    if (digitalRead(Apin) == LOW)
    {
        if (digitalRead(Apin) != lastStateA) { buttonAPressed(); }
        lastStateA = LOW;
    }
    else { lastStateA = HIGH; }

    if (digitalRead(Qpin) == LOW)
    {
        if (digitalRead(Qpin) != lastStateQ) { buttonQPressed(); }
        lastStateQ = LOW;
    }
    else { lastStateQ = HIGH; }
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

Keyboard::Keyboard()
{
    cursorX = 0;
    cursorY = 0;

    lastStateW = HIGH;
    lastStateA = HIGH;
    lastStateS = HIGH;
    lastStateD = HIGH;
    lastStateE = HIGH;
    lastStateQ = HIGH;
}