#include <Arduino.h>
#define PIN_2 2
#include <iostream>
#include "rectangle.h"
#include "TestCase.h"
#include "TestResult.h"
#include "Manager.h"

void setup()
{
  Serial.println("Setup");

  Serial.begin(115200);
  BLEManager *pBLEManager = new BLEManager;
  pBLEManager->onInit();
}

void loop()
{
}