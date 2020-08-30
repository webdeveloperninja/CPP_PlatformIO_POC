#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "Manager.h"
#include <iostream>
#include <Arduino.h>

#define DEVICE_SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"

#define GPIO2_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define GPIO4_CHARACTERISTIC_UUID "7a6a8cb2-2413-4c80-a285-4af758cd0223"

class Gpio2Handler : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        std::string value = pCharacteristic->getValue();

        if (value.length() > 0)
        {
            if (value == "start_process")
            {
                Serial.print("Start process");
                digitalWrite(2, HIGH);
            }

            if (value == "stop_process")
            {
                Serial.print("Stop process");
                digitalWrite(2, LOW);
            }
        }
    }
};

class Gpio4Handler : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        std::string value = pCharacteristic->getValue();

        if (value.length() > 0)
        {
            if (value == "start_process")
            {
                Serial.print("Start process");
                digitalWrite(4, HIGH);
            }

            if (value == "stop_process")
            {
                Serial.print("Stop process");
                digitalWrite(4, LOW);
            }
        }
    }
};

void BLEManager::onInit(std::string *pDeviceName)
{
    BLEDevice::init(*pDeviceName);
    pServer = BLEDevice::createServer();

    BLEService *pService = pServer->createService(DEVICE_SERVICE_UUID);

    pGpio2Characteristic = pService->createCharacteristic(
        GPIO2_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE |
            BLECharacteristic::PROPERTY_NOTIFY |
            BLECharacteristic::PROPERTY_INDICATE);

    pGpio4Characteristic = pService->createCharacteristic(
        GPIO4_CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE |
            BLECharacteristic::PROPERTY_NOTIFY |
            BLECharacteristic::PROPERTY_INDICATE);

    pGpio2Characteristic->setCallbacks(new Gpio2Handler());
    pGpio4Characteristic->setCallbacks(new Gpio4Handler());

    pService->start();

    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->start();
}

void BLEManager::beaconNotify(NotifyPayload notifyPayload)
{
    String pin2payload = String(notifyPayload.pin2Voltage);
    String pin4payload = String(notifyPayload.pin4Voltage);

    pGpio2Characteristic->setValue(pin2payload.c_str());
    pGpio2Characteristic->notify();
    pGpio4Characteristic->setValue(pin4payload.c_str());
    pGpio4Characteristic->notify();
}
