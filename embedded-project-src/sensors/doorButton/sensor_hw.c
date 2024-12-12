#include "sensor_hw.h"
#include "sensor_on_read.h"

void door_button_hw_init(void) {
    // Set as input button
    GPIO_setAsInputPinWithPullUpResistor(DOOR_BUTTON_PORT, DOOR_BUTTON_PIN);

    // enable interrupts for that gpio
    GPIO_enableInterrupt(DOOR_BUTTON_PORT, DOOR_BUTTON_PIN);

    // enable interrupts for port
    Interrupt_enableInterrupt(DOOR_BUTTON_INTERRUPT_PORT);

    // activate interrupt notification
    Interrupt_enableMaster();
}


void PORT3_IRQHandler(void)
{

    uint32_t status = GPIO_getInterruptStatus(DOOR_BUTTON_PORT, DOOR_BUTTON_PIN);

    if (status & DOOR_BUTTON_PIN)
    {
        // clear interrupt flag
        GPIO_clearInterruptFlag(DOOR_BUTTON_PORT, DOOR_BUTTON_PIN);

        // button press
        door_button_on_press();
    }

}
