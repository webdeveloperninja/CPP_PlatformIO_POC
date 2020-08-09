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

void setup()
{
  EEPROM.begin(1024);

  Serial.begin(115200);
  Configuration config = {
      "Rob"};

  BLEManager *pBLEManager = new BLEManager;
  std::string deviceName = "My ESP32";
  pBLEManager->onInit(&deviceName);

  int eeAddress = 0;
  EEPROM.put(eeAddress, config);
  EEPROM.commit();

  Configuration customVar;
  EEPROM.get(eeAddress, customVar);

  Serial.print("Value");
  Serial.println(customVar.name);
}

void loop()
{
}