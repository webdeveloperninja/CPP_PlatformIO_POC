#include <Arduino.h>
#define PIN_2 2
#include <iostream>
#include "Manager.h"

BLEManager *pBLEManager;

void setup()
{
  std::string deviceName = "My ESP32";
  Serial.begin(115200);

  pBLEManager = new BLEManager;
  pBLEManager->onInit(&deviceName);
}

void loop()
{
  delay(3);
  pBLEManager->beaconNotify();
}