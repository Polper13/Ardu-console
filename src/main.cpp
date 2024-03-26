#include <Arduino.h>

#include <drawer.h>


Drawer* drawer;

void setup()
{
  Serial.begin(9600);

  drawer = new Drawer(8);

  for (int i = 2; i <= 7; i++)
    pinMode(i, INPUT_PULLUP);
}

void loop()
{
  drawer->checkForDraws();
}