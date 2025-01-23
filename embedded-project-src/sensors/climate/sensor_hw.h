#ifndef __SENSOR_HW_H__
#define __SENSOR_HW_H__


#include "msp.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


#define SENSOR_IRQn

uint32_t cal30;
uint32_t cal85;
float calDifference;

//init sensor
void climate_sensor_hw_init(void);

//read temperature of sensor 
float climate_sensor_hw_readTemperature(void);

//ISR: INTERRUPT
// void ADC14_IRQHandler(void);

/*
MAIN 
// Inizializzazione dell'hardware 
    climate_sensor_hw_init();

//     Mette il microcontrollore in modalità LPM0 per risparmiare energia 
    while (1)
    {
        PCM_gotoLPM0();
    }

*/



#endif