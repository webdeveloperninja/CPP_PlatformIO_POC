#pragma once
#include "TestResult.h"

class TestCase
{
public:
    ~TestCase();

    virtual void onInit();
    virtual TESTRESULT assertCase();
};