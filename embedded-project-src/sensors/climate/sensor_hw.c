#include "sensor_hw.h"
#include "sensor_on_read.h" //contains functions that process the temperature value
#include "tools/HAL_I2C.h" //I2C communication drivers
#include "tools/HAL_TMP006.h" //Sensor specific driver TMP006
#include <stdint.h>

//sensor calibration
uint32_t cal30;
uint32_t cal85;
//variables for conversion
float calDifference;
float tempC;

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

//sensor interrupt handling 
/*
void ADC14_IRQHandler(void){
    uint64_t status;
    int16_t conRes;

    status = ADC14_getEnabledInterruptStatus();
    ADC14_clearInterruptFlag(status);

    if (status & ADC_INT0)
    {
        conRes = ((ADC14_getResult(ADC_MEM0) - cal30) * 55);
        tempC = (conRes / calDifference) + 30.0f;

        // Turn on/off led based on the temperature
        if (tempC < 19.0f)
        {
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0); // turn on red
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);  // turn off green
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);  // turn ogg blue 
        }
        else if (tempC >= 19.0f && tempC <= 22.0f)
        {
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);  // turn off red
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1); // turn on green
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);  // turn off blue
        }
        else if (tempC > 22.0f && tempC <= 25.0f)
        {
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);  // turn off red
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1); // turn on green
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);  // turn off blue
        }
        else if (tempC > 25.0f)
        {
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);  // turn off red
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);  // turn off green
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2); // turn on blue
        }
    }
}

*/





