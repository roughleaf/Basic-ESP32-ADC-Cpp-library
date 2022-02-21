#pragma once

#include "driver/adc.h"
#include "esp_adc_cal.h"

// ADC Calibration
#if CONFIG_IDF_TARGET_ESP32
constexpr static const esp_adc_cal_value_t ADC_CALI_SCHEME = ESP_ADC_CAL_VAL_EFUSE_VREF;
#elif CONFIG_IDF_TARGET_ESP32S2
constexpr static const esp_adc_cal_value_t ADC_CALI_SCHEME = ESP_ADC_CAL_VAL_EFUSE_TP;
#elif CONFIG_IDF_TARGET_ESP32C3
constexpr static const esp_adc_cal_value_t ADC_CALI_SCHEME = ESP_ADC_CAL_VAL_EFUSE_TP;
#elif CONFIG_IDF_TARGET_ESP32S3
constexpr static const esp_adc_cal_value_t ADC_CALI_SCHEME = ESP_ADC_CAL_VAL_EFUSE_TP_FIT;
#endif

namespace CPPANALOG
{
    class CppAdc1
    {
        private:
            adc_bits_width_t _bitWidth = ADC_WIDTH_BIT_12;
            adc1_channel_t _adc1Channel;
            adc_atten_t _adcAttenuation = ADC_ATTEN_DB_11;
            bool _calEnabled = false;
            esp_adc_cal_characteristics_t _adc1_characteristics;
            bool _checkCalFuse();
            
        public:
            CppAdc1(void);
            CppAdc1(adc1_channel_t channel);
            void SetChannel(adc1_channel_t channel);
            esp_err_t SetBitWidth(adc_bits_width_t bitWidth);
            esp_err_t SetBitWidth(int bitWidth);
            esp_err_t SetAttenuation(adc_atten_t attenuation);
            bool CheckCalFuse();
            int GetRaw();
            int GetVoltage();
    }; // CppAdc Class
} // CPPANALOG namespace