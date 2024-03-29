#include "Engine.h"

Engine::Engine(uint8_t targetUpdateRate)
    :interval(1000 / targetUpdateRate), display(4), drawer(), keyboard()
{
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);
}

void Engine::checkForUpdates()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        // updates
        keyboard.update();

        // draw call
        drawer.drawFrame(display, keyboard);
    }
}