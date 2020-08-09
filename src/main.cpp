#include <Arduino.h>
#define PIN_2 2
#include <iostream>
#include "rectangle.h"
#include "TestCase.h"
#include "TestResult.h"
#include "Manager.h"

void setup()
{
  Serial.begin(115200);
  BLEManager *pBLEManager = new BLEManager;
  std::string deviceName = "My ESP32";
  pBLEManager->onInit(&deviceName);
}

void loop()
{
}