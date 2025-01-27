#include "sensor_hw.h"
#include "sensor_on_read.h"

void irrigation_button_hw_init(void) {
    // Set as input button
    GPIO_setAsInputPinWithPullUpResistor(IRRIGATION_BUTTON_PORT, IRRIGATION_BUTTON_PIN);

    // enable interrupts for that gpio
    GPIO_enableInterrupt(IRRIGATION_BUTTON_PORT, IRRIGATION_BUTTON_PIN);

    // enable interrupts for port
    Interrupt_enableInterrupt(IRRIGATION_BUTTON_INTERRUPT_PORT);

    // activate interrupt notification
    Interrupt_enableMaster();
}


void PORT5_IRQHandler(void)
{
    uint32_t status = GPIO_getInterruptStatus(IRRIGATION_BUTTON_PORT, IRRIGATION_BUTTON_PIN);

    if (status & IRRIGATION_BUTTON_PIN)
    {
        // clear interrupt flag
        GPIO_clearInterruptFlag(IRRIGATION_BUTTON_PORT, IRRIGATION_BUTTON_PIN);

        // call button on press function
        irrigation_button_on_press();
    }

}
