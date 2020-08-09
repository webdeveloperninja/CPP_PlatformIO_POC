#pragma once
#include "TestResult.h"

class FlashStorageManager
{
public:
    ~FlashStorageManager();

    void write();
    void read();
};