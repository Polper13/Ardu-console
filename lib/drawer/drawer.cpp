#include "drawer.h"

void Drawer::drawFrame()
{
    display.clearDisplay();
    
    keyboard.drawKeyboard(display);
    keyboard.drawCursor(display, frameIndex);

    // display.setTextSize(1);
    // display.setTextColor(WHITE);
    // display.setCursor(0, 0);
    // display.write("yo");

    display.display();
}

Drawer::Drawer(uint8_t targetFPS)
    :interval(1000 / targetFPS), display(4), keyboard() 
{
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();

    frameIndex = 0;
}

void Drawer::checkForDraws()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        if (frameIndex == 7)
            frameIndex = 0;
        else
            frameIndex++;

        drawFrame();
    }
}