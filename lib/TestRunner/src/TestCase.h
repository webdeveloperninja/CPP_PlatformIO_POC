#pragma once

class TestCase
{
public:
    ~TestCase();

    virtual void onInit();
    virtual void assertCase();
};