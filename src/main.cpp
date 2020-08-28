#include <Arduino.h>
#define PIN_2 2
#include <iostream>
#include "Manager.h"

BLEManager *pBLEManager;

int digitalReadOutputPin(uint8_t pin)
{
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  if (port == NOT_A_PIN)
    return LOW;

  return (*portOutputRegister(port) & bit) ? HIGH : LOW;
}

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

  int pin2Voltage = digitalReadOutputPin(2);
  NotifyPayload payload;
  payload.pin2Voltage = pin2Voltage;

  pBLEManager->beaconNotify(payload);
}