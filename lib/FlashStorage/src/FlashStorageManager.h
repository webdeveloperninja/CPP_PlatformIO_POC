#include <EEPROM.h>
#include <Arduino.h>

template <class T>
int writeToFlash(const T value)
{
    EEPROM.put(0, value);
    return 1;
}

template <class T>
int readFromFlash(int ee, T &value)
{
    EEPROM.get(ee, value);
    return 1;
}