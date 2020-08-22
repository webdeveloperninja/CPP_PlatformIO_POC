#include <Arduino.h>
#define PIN_2 2
#include <iostream>
#include "TestCase.h"
#include "TestResult.h"
#include "Manager.h"
#include "FlashStorageManager.h"
#include <EEPROM.h>

struct Configuration
{
  char name[10];
};

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