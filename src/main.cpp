#include <Arduino.h>
#include <Drawer.h>
#include <Engine.h>


Engine* enginePtr;

void setup()
{
  enginePtr = new Engine(8);

  for (int i = 2; i <= 7; i++)
    pinMode(i, INPUT_PULLUP);
}

void loop()
{
  enginePtr->checkForUpdates();
}