#include "sensor_hw.h"
#include "sensor_on_read.h" //contains functions that process the temperature value
#include "tools/HAL_I2C.h" //I2C communication drivers
#include "tools/HAL_TMP006.h" //Sensor specific driver TMP006
#include <stdint.h>


void climate_sensor_hw_init(void){
    Init_I2C_GPIO(); //configure pin I2C
    I2C_init(); //inizalization communication I2C
    /* Initialize TMP006 temperature sensor */
    TMP006_init(); //configuration TMP006 sensor 
    __delay_cycles(100000); //waiting for sensor to stabilize

}

float climate_sensor_hw_readTemperature(void){
    float tempFarenheit = TMP006_getTemp();
    float tempC = (tempFarenheit - 32) * 5.0/9.0;
    return tempC - 10;
}
