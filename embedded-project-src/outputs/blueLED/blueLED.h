#ifndef __BLUELED_HW_H__
#define __BLUELED_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdbool.h>

/**
 * Boosterpack blue LED J4.37 maps to Port 5.6
 */
#define LED_PORT GPIO_PORT_P2
#define LED_PIN GPIO_PIN2

void led_hw_init(void);
void toggle_led(bool active);

#endif
