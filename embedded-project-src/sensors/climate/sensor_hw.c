#include "sensor_hw.h"
#include "sensor_on_read.h" //per climate sensor interrupt handling

void climate_sensor_hw_init(void){
    //init I2C and sensor OPT3001
    HAL_I2C_H_Init();
    HAL_OPT3001_H_Init();
}

int climate_sensor_hw_readTemperature(void){
    return HAL_OPT3001_H_ReadTemperature(); //read the temperature from OPT3001
}


/*per climate sensor interrupt handling */
void climate_sensor_hw_configureInterrupt(void){
    HAL_OPT3001_EnableInterrupt(); //configure sensor for having fast switch
}
void climate_sensor_hw_handleInterrupt(void){
    climate_sensor_on_read_handleTemperature();
}