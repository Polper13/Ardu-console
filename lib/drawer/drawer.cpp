#include "drawer.h"

void Drawer::drawFrame(Keyboard& keyboard, Menu& menu)
{
    display.clearDisplay();
    
    // keyboard.drawKeyboard(display);
    // keyboard.drawCursor(display, frameIndex);

    menu.drawMenu(display);

    display.display();

    // update frame counter
    if (frameIndex == 7)
        frameIndex = 0;
    else
        frameIndex++;
}

Drawer::Drawer()
    :display(4)
{
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);
    frameIndex = 0;
}