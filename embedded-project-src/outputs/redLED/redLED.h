#ifndef __REDLED_HW_H__
#define __REDLED_HW_H__

#include <stdbool.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/**
 * 
 */
#define RED_LED_PORT GPIO_PORT_P2
#define RED_LED_PIN GPIO_PIN6

void red_led_hw_init(void);
void red_toggle_led(bool active);

#endif
