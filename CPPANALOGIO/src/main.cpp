#include "main.h"

Main App;

void Main::run(void)
{
    std::cout << "Raw Data: " << ADC.GetRaw() << '\n';
    std::cout << "Calibrated voltage: " << ADC.GetVoltage() << "mV\n";
    std::cout << "Set Output Voltage value to ADC Value: "<< (ADC.GetRaw()/16) <<'\n';
    DAC.SetVoltageByValue(ADC.GetRaw()/16);
}

void Main::setup(void)
{
    ADC.SetBitWidth(12);
    DAC.DacEnable();
}

extern "C" void app_main(void)
{
    App.setup();
     while (true)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
        App.run();
    }    
}
