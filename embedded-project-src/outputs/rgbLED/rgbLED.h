#ifndef __RGBLED_HW_H__
#define __RGBLED_HW_H__

#include <stdbool.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/**
 *  J1.5 maps to Port 4.1
 */
#define RGB_LED_PORT GPIO_PORT_P4
#define RGB_LED_PIN GPIO_PIN1

void rgb_led_hw_init(void);
void rgb_toggle_led(bool active);

#endif
