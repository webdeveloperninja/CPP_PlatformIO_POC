#include <Arduino.h>
#define ONBOARD_LED 2
#include <iostream>
#include "rectangle.h"

void setup()
{
  Serial.begin(115200);
  pinMode(ONBOARD_LED, OUTPUT);
}

void loop()
{
  delay(1000);
  digitalWrite(ONBOARD_LED, HIGH);
  delay(100);
  digitalWrite(ONBOARD_LED, LOW);

  Rectangle rectA{5, 5};

  Serial.println("Area of rectangle");
  Serial.println(rectA.getArea());
}