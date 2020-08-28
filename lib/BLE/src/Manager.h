#include <BLEDevice.h>
#include <Arduino.h>

#pragma once

struct NotifyPayload
{
    int pin2Voltage;
};

class BLEManager
{
public:
    void onInit(std::string *pDeviceName);
    void beaconNotify(NotifyPayload notifyPayload);

private:
    BLEServer *pServer;
    BLECharacteristic *pConfigurationCharacteristic;
    BLECharacteristic *pGpio2Characteristic;
};