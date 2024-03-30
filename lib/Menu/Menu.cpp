#include "Menu.h"

#include <customCharacters.h>

Menu::Menu()
{
    selectionIndex = 0;
}

void Menu::drawMenu(Adafruit_SH1106& display)
{
    // text settings
    display.setTextSize(1);
    display.setTextColor(WHITE);

    // draw menu selector
    display.drawBitmap(9, 29, menuSelector, 4, 9, WHITE);

    // draw middle button
    display.drawFastVLine(16, 27, 12, WHITE);
    display.drawFastVLine(113, 27, 12, WHITE);

    display.drawFastHLine(17, 26, 96, WHITE);
    display.drawFastHLine(17, 37, 96, WHITE);
    display.drawFastHLine(17, 39, 96, WHITE);

    display.setCursor(19, 29);
    display.write(menuButtons[selectionIndex]);

    // draw upper button
    if (selectionIndex != 0)
    {
        display.drawFastVLine(9, 8, 12, WHITE);
        display.drawFastVLine(106, 8, 12, WHITE);

        display.drawFastHLine(10, 7, 96, WHITE);
        display.drawFastHLine(10, 18, 96, WHITE);
        display.drawFastHLine(10, 20, 96, WHITE);

        display.setCursor(12, 10);
        display.write(menuButtons[selectionIndex - 1]);
    }

    // draw bottom button
    if (selectionIndex != lastButtonIndex)
    {
        display.drawFastVLine(9, 46, 12, WHITE);
        display.drawFastVLine(106, 46, 12, WHITE);

        display.drawFastHLine(10, 45, 96, WHITE);
        display.drawFastHLine(10, 56, 96, WHITE);
        display.drawFastHLine(10, 58, 96, WHITE);

        display.setCursor(12, 48);
        display.write(menuButtons[selectionIndex + 1]);
    }
}

void Menu::update(Input& input)
{
    // handle input
    if (input.wPressedDown && selectionIndex != 0)
        selectionIndex--;
    
    if (input.sPressedDown && selectionIndex != lastButtonIndex)
        selectionIndex++;
}
