#ifndef __RGBLED_HW_H__
#define __RGBLED_HW_H__

#include <stdbool.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


#define RGB_LED_RED_PORT GPIO_PORT_P2
#define RGB_LED_GREEN_PORT GPIO_PORT_P2
#define RGB_LED_BLUE_PORT GPIO_PORT_P5

#define RGB_LED_RED_PIN GPIO_PIN6
#define RGB_LED_GREEN_PIN GPIO_PIN4
#define RGB_LED_BLUE_PIN GPIO_PIN6

/**
  * J4.39 -> RED 2.6
  * J4.38 -> GREEN 2.4
  * J4.37 -> BLUE 5.6
  * Native rgb led maps to ports 2.0, 2.1, 2.2
 */
void rgb_led_hw_init(void);

void rgb_set_blue();
void rgb_set_red();
void rgb_set_off();

#endif
