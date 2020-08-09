#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "Manager.h"
#include <iostream>
#include <Arduino.h>

#define DEVICE_SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CONFIGURATION_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class ConfigurationCharacteristicHandler : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        std::string value = pCharacteristic->getValue();

        if (value.length() > 0)
        {
            Serial.println("*********");
            Serial.print("New value: ");
            for (int i = 0; i < value.length(); i++)
                Serial.print(value[i]);

            Serial.println();
            Serial.println("*********");
        }
    }
};

void BLEManager::onInit(std::string *pDeviceName)
{
    BLEDevice::init(*pDeviceName);
    pServer = BLEDevice::createServer();

    BLEService *pService = pServer->createService(DEVICE_SERVICE_UUID);

    BLECharacteristic *pConfigurationCharacteristic = pService->createCharacteristic(
        CONFIGURATION_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE);

    pConfigurationCharacteristic->setCallbacks(new ConfigurationCharacteristicHandler());

    pConfigurationCharacteristic->setValue("Hello World");
    pService->start();

    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
}
