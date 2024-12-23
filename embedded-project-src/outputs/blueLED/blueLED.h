#ifndef __BLUELED_HW_H__
#define __BLUELED_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdbool.h>

/**
 * Boosterpack blue LED J4.37 maps to Port 5.6
 */

// LED constants
#define LED_PORT GPIO_PORT_P5
#define LED_PIN GPIO_PIN6

// Timer constants
#define TIMER_PERIOD   46875 //1 second for 3MHz / 64
#define IRRIGATION_DURATION 10


// LED functions
void led_hw_init(void);
void toggle_led(bool active);

// Timer functions
void timerA3_start(void);
void timerA3_reset(void);
void TA3_0_IRQHandler(void);

#endif
