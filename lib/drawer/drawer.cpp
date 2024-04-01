#include "Drawer.h"
#include "5x5characters.h"

Drawer::Drawer()
    :display(4)
{
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);
    frameIndex = 0;
}

void Drawer::drawFrame(Mode& mode, Keyboard& keyboard, Menu& menu, Calculator& calculator)
{
    display.clearDisplay();

    String equation = "(2+2*2)*(8-4)+(2137+69)/56+2*(21*45+2)";
    
    switch (mode)
    {
    case Mode::menu:
        menu.drawMenu(display);
        break;

    case Mode::calculator:
        keyboard.drawKeyboard(display);
        keyboard.drawCursor(display, frameIndex);

        calculator.drawEquation(display, equation, 4, 4);

        // text try
        // display.drawBitmap(5, 4, smallLeftBracket, 5, 5, WHITE);
        // display.drawBitmap(10, 4, smallTwo, 5, 5, WHITE);
        // display.drawBitmap(15, 4, smallAdd, 5, 5, WHITE);
        // display.drawBitmap(20, 4, smallTwo, 5, 5, WHITE);
        // display.drawBitmap(25, 4, smallMultiply, 5, 5, WHITE);
        // display.drawBitmap(30, 4, smallTwo, 5, 5, WHITE);
        // display.drawBitmap(35, 4, smallRightBracket, 5, 5, WHITE);

        // display.drawBitmap(40, 4, smallMultiply, 5, 5, WHITE);

        // display.drawBitmap(45, 4, smallLeftBracket, 5, 5, WHITE);
        // display.drawBitmap(50, 4, smallEight, 5, 5, WHITE);
        // display.drawBitmap(55, 4, smallSubtract, 5, 5, WHITE);
        // display.drawBitmap(60, 4, smallFour, 5, 5, WHITE);
        // display.drawBitmap(65, 4, smallRightBracket, 5, 5, WHITE);

        break;
    
    default:
        break;
    }

    display.display();

    // update frame counter
    if (frameIndex == 7)
        frameIndex = 0;
    else
        frameIndex++;
}