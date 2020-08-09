#include <BLEDevice.h>
#include <Arduino.h>

#pragma once

class BLEManager
{
public:
    void onInit(std::string *pDeviceName);

private:
    BLEServer *pServer;
};