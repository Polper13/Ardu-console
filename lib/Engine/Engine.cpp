#include "Engine.h"

Engine::Engine(uint8_t targetUpdateRate)
    :interval(1000 / targetUpdateRate), drawer(), keyboard(), menu(), input()
{
    
}

void Engine::checkForUpdates()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        // updates
        input.update();
        menu.update(input);

        // draw call
        drawer.drawFrame(keyboard, menu);
    }
}