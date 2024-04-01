#include "drawer.h"

void Drawer::drawFrame(Mode& mode, Keyboard& keyboard, Menu& menu)
{
    display.clearDisplay();
    
    switch (mode)
    {
    case Mode::menu:
        menu.drawMenu(display);
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

Drawer::Drawer()
    :display(4)
{
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);
    frameIndex = 0;
}