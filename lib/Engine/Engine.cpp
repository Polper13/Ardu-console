#include "Engine.h"

Engine::Engine(uint8_t targetUpdateRate)
    :interval(1000 / targetUpdateRate), drawer(), keyboard(), menu(), input(), calculator()
{
    mode = Mode::menu;
}

void Engine::checkForUpdates()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        // updates
        update();

        // draw call
        drawer.drawFrame(mode, keyboard, menu, calculator);
    }
}

void Engine::update()
{
    switch (mode)
    {
    case Mode::menu:
        input.update();
        menu.update(input, mode);
        break;

    case Mode::calculator:
        input.update();
        keyboard.update(input);
    
    default:
        break;
    }
}