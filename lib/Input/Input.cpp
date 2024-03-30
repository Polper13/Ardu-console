#include "Input.h"

Input::Input()
{
    for (int i = 0; i < 6; i++)
    {
        *pressedDownVariablesPtr[i] = false;
    }
}

void Input::update()
{
    for (int i = 0; i <= 5; i++)
    {
        if (digitalRead(i + 2) == LOW) // i + 2 because first pin is pin nr 2
        {
            if (lastButtonStates[i] == HIGH)
                *pressedDownVariablesPtr[i] = true;
            else
                *pressedDownVariablesPtr[i] = false;

            lastButtonStates[i] = LOW;
        }
        else
        {
            lastButtonStates[i] = HIGH;
            *pressedDownVariablesPtr[i] = false;
        }
    }
}

