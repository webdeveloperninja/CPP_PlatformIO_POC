#include "FlashStorageManager.h"
#include <EEPROM.h>
#include <Arduino.h>

template <class T>
int write(int ee, const T &value)
{
    const byte *p = (const byte *)(const void *)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
        EEPROM.write(ee++, *p++);
    return i;
}

template <class T>
int read(int ee, T &value)
{
    byte *p = (byte *)(void *)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
        *p++ = EEPROM.read(ee++);
    return i;
}

int writeFlash(std::string key, std::string value)
{
    return 0;
}