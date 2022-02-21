set(SOURCES main.cpp
            CPPANALOG/cppadc.cpp)
            
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS .  ../include/CPPANALOG
                    REQUIRES "esp_adc_cal")