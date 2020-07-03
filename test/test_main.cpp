#include <Arduino.h>
#include <unity.h>
#include "rectangle.h"

String STR_TO_TEST;

void test_rectangle_area(void)
{
    Rectangle rectA{5, 5};
    const float expectedArea = 25;

    TEST_ASSERT_EQUAL_FLOAT(expectedArea, rectA.getArea());
}

void setup()
{
    delay(2000); // service delay
    UNITY_BEGIN();

    RUN_TEST(test_rectangle_area);
    UNITY_END(); // stop unit testing
}

void loop()
{
}