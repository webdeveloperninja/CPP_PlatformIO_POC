#include <BLEDevice.h>
#include <Arduino.h>

#pragma once

class BLEManager
{
public:
    void onInit(std::string *pDeviceName);
    void beaconNotify();

private:
    BLEServer *pServer;
    BLECharacteristic *pConfigurationCharacteristic;
    BLECharacteristic *pGpio2Characteristic;
};