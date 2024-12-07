#include "sensor_hw.h"
#include "sensor_on_read.h" 
#include <stdint.h>

void climate_sensor_hw_init(void){
    //init I2C and sensor TMP006
    HAL_I2C_H_Init();
    
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4,GPIO_PIN1); //GPIO P4.1 like an input with pull-up
    GPIO_interruptEdgeSelect(GPIO_PORT_P4,GPIO_PIN1,GPIO_HIGH_TO_LOW_TRASITION); //type of edge (high to low)
    GPIO_clearInterrupt(GPIO_PORT_P4,GPIO_PIN1); //delete flag of interrupt scarts 
    GPIO_enableInterrupt(GPIO_PORT_P4,GPIO_PIN1); //abilitate interrpt for P4.1

    Interrupt_enableInterrupt(SENSOR_IRQn);//abilitate for NVIC
    Interrupt_enableMaster(); //abilitate master interrpt 

}

int climate_sensor_hw_readTemperature(void){
    uint_t rawData=HAL_I2C_Read(TMP006_I2C_ADDRESS,TMP066_TEMPERATURE_REGISTER);

    return (int)rawData*0.03125; //specific conversion of TMP006 for gradi 
}


void climate_sensor_PORT4_IRQHandler(void){
    if(GPIO_getInterruptStatus(GPIO_PORT_P4,GPIO_PIN1)){
        climate_sensor_on_read_handleTemperature();
        GPIO_clearInterrupt(GPIO_PORT_P4,GPIO_PIN1);
    }

}


/*
//precedente climate sensor interrupt handling 
void climate_sensor_hw_configureInterrupt(void){
    HAL_OPT3001_EnableInterrupt(); //configure sensor for having fast switch
}
void climate_sensor_hw_handleInterrupt(void){
    climate_sensor_on_read_handleTemperature();
}
*/