#include "sensor_hw.h"
#include "sensor_on_read.h" 
#include "tools/HAL_I2C.h"
#include "tools/HAL_TMP006.h"
#include <stdint.h>

uint32_t cal30;
uint32_t cal85;
float calDifference;
float tempC;

void climate_sensor_hw_init(void){
    /* configuration of LED */
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0); // red LED 
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1); // green LED 
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2); // blue LED 
    
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0); // red:turn off 
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1); // green:turn off 
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2); // blue:turn off 

    Init_I2C_GPIO();
    I2C_init();
    /* Initialize TMP006 temperature sensor */
    TMP006_init();
    __delay_cycles(100000);

}

float climate_sensor_hw_readTemperature(void){
    float tempFarenheit = TMP006_getTemp();
    float tempC = (tempFarenheit - 32) * 5.0/9.0;
    return tempC;
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





