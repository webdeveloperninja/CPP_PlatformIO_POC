#include <Arduino.h>
#define ONBOARD_LED 2
#include <iostream>
#include "rectangle.h"
#include "TestCase.h"

class LedShouldTurnOn : public TestCase
{
public:
  void onInit()
  {
    Serial.println("onInit");
  }

  void assertCase()
  {
    Serial.println("assertCase");
  }
};

void setup()
{
  Serial.begin(115200);
  pinMode(ONBOARD_LED, OUTPUT);
}

void loop()
{
  LedShouldTurnOn *pLedShouldTurnOn = new LedShouldTurnOn;

  pLedShouldTurnOn->onInit();
  pLedShouldTurnOn->assertCase();
  delay(5000);
}