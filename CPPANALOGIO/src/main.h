#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <iostream>
#include "analogio.h"

class Main final
{
public:
    void run(void);
    void setup(void);

    CPPANALOG::CppAdc1 ADC{ADC1_CHANNEL_7}; // pin 35

    CPPANALOG::CppDac DAC{DAC_CHANNEL_1}; // pin 25

}; // Main Class
