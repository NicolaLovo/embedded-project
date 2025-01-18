#ifndef __BLUELED_HW_H__
#define __BLUELED_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdbool.h>

/**
 * Boosterpack blue LED: J4.37 maps to Port 5.6
 *
 * For external led: J1.6 maps to Port 4.3
 */
#define LED_PORT GPIO_PORT_P4
#define LED_PIN GPIO_PIN3

void led_hw_init(void);
void toggle_led(bool active);

#endif
