#ifndef __REDLED_HW_H__
#define __REDLED_HW_H__

#include <stdbool.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/**
 *  J1.5 maps to Port 4.1
 */
#define RED_LED_PORT GPIO_PORT_P4
#define RED_LED_PIN GPIO_PIN1

void red_led_hw_init(void);
void red_toggle_led(bool active);

#endif
