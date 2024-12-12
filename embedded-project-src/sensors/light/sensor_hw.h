#ifndef __LIGHT_HW_H__
#define __LIGHT_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


/**
 * I2C is mapped to port 6.4 and 6.5
 * Light sensor interrupt is mapped to port4.6
 * Slide 6
 * https://didatticaonline.unitn.it/dol/pluginfile.php/1882808/mod_resource/content/0/Lecture-14.pdf
 */
#define LIGHT_PORT GPIO_PORT_P4
#define LIGHT_PIN GPIO_PIN6
#define LIGHT_INTERRUPT_PORT INT_PORT4


/**
 * Contains hardware specific code:
 * - light sensor initialization 
 * - light sensor interrupt handling
 */
void light_hw_init(void);

/**
 * Manually read light sensor value
 */
float read_light(void);

/**
 * Interrupt handler for door button
 */
//void PORT4_IRQHandler(void);

#endif
