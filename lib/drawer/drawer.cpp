#include "drawer.h"

void Drawer::drawFrame(Adafruit_SH1106& display, Keyboard& keyboard)
{
    display.clearDisplay();
    
    keyboard.drawKeyboard(display);
    keyboard.drawCursor(display, frameIndex);

    display.display();

    // update frame counter
    if (frameIndex == 7)
        frameIndex = 0;
    else
        frameIndex++;
}

Drawer::Drawer()
{
    frameIndex = 0;
}