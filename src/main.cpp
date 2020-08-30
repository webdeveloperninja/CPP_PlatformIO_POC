#include <Arduino.h>
#include <iostream>
#include "Manager.h"

BLEManager *pBLEManager;

const int gpio2 = 2;
const int gpio4 = 4;

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
  pinMode(gpio2, OUTPUT);
  pinMode(gpio4, OUTPUT);

  std::string deviceName = "My ESP32";
  Serial.begin(115200);

  pBLEManager = new BLEManager;
  pBLEManager->onInit(&deviceName);
}

void loop()
{
  delay(3);

  int pin2Voltage = digitalReadOutputPin(2);
  int pin4Voltage = digitalReadOutputPin(4);

  NotifyPayload payload;
  payload.pin2Voltage = pin2Voltage;
  payload.pin4Voltage = pin4Voltage;

  pBLEManager->beaconNotify(payload);
}