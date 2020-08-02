#include <Arduino.h>
#define PIN_2 2
#include <iostream>
#include "rectangle.h"
#include "TestCase.h"
#include "TestResult.h"

int digitalReadOutputPin(uint8_t pin)
{
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  if (port == NOT_A_PIN)
    return LOW;

  return (*portOutputRegister(port) & bit) ? HIGH : LOW;
}

class LedShouldTurnOn : public TestCase
{
public:
  void onInit()
  {
    pinMode(PIN_2, OUTPUT);
    digitalWrite(PIN_2, HIGH);
  }

  TESTRESULT assertCase()
  {
    int pin2Voltage = digitalReadOutputPin(PIN_2);
    TESTRESULT result;

    if (pin2Voltage == HIGH)
    {
      result.hasFailed = false;
    }
    else
    {
      result.hasFailed = true;
    }

    return result;
  }
};

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  LedShouldTurnOn *pLedShouldTurnOn = new LedShouldTurnOn;

  pLedShouldTurnOn->onInit();
  TESTRESULT result = pLedShouldTurnOn->assertCase();

  Serial.println("Test failed?");
  Serial.println(result.hasFailed);

  delay(5000);
}