#include "tools/HAL_I2C.h"
#include "tools/HAL_OPT3001.h"
#include "sensor_hw.h"


void light_hw_init_interrupts(void)
{
    /**
    // Set light port as input with pull-up resistor
    GPIO_setAsInputPinWithPullUpResistor(LIGHT_PORT, LIGHT_PIN);

    // Enable interrupts for light port
    GPIO_enableInterrupt(LIGHT_PORT, LIGHT_PIN);

    // Enable global interrupts
    Interrupt_enableInterrupt(LIGHT_INTERRUPT_PORT);

    // activate interrupt notification
    Interrupt_enableMaster();
    */
}

void light_hw_init(void) {
    /* Initialize I2C communication */
    Init_I2C_GPIO();
    I2C_init();

    /* Initialize OPT3001 digital ambient light sensor */
    OPT3001_init();

    light_hw_init_interrupts();
}


float read_light(void) {
    float lux = OPT3001_getLux();
    return lux;
}


bool light_is_day() {
    float lux = read_light();
    return lux >= DAY_THRESHOLD;
}

/*
void PORT4_IRQHandler(void)
{
    uint32_t status = GPIO_getEnabledInterruptStatus(LIGHT_PORT);

    if (status & LIGHT_PIN)
    {
        // Read light sensor value (optional)
        float lightReading = read_light();

        GPIO_clearInterruptFlag(LIGHT_PORT, LIGHT_PIN);

    }
}*/
