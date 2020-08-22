#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "Manager.h"
#include <iostream>
#include <Arduino.h>

#define DEVICE_SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CONFIGURATION_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

const int LED_PIN = 2;

class ConfigurationCharacteristicHandler : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        std::string value = pCharacteristic->getValue();

        if (value.length() > 0)
        {
            pinMode(LED_PIN, OUTPUT);

            if (value == "start_process")
            {
                Serial.print("Start process");
                digitalWrite(LED_PIN, HIGH);
            }

            if (value == "stop_process")
            {
                Serial.print("Stop process");
                digitalWrite(LED_PIN, LOW);
            }
        }
    }
};

void BLEManager::onInit(std::string *pDeviceName)
{
    BLEDevice::init(*pDeviceName);
    pServer = BLEDevice::createServer();

    BLEService *pService = pServer->createService(DEVICE_SERVICE_UUID);

    pConfigurationCharacteristic = pService->createCharacteristic(
        CONFIGURATION_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE |
            BLECharacteristic::PROPERTY_NOTIFY |
            BLECharacteristic::PROPERTY_INDICATE);

    pConfigurationCharacteristic->setCallbacks(new ConfigurationCharacteristicHandler());
    pConfigurationCharacteristic->setValue("Hello World");

    pService->start();

    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
}

void BLEManager::beaconNotify()
{
    pConfigurationCharacteristic->notify();
}
