#ifndef __IRRIGATION_BUTTON_HW_H__
#define __IRRIGATION_BUTTON_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>



/**
 * Boosterpack S1 button J4.33 maps to Port 5.1
 * Slide 6
 * https://didatticaonline.unitn.it/dol/pluginfile.php/1882808/mod_resource/content/0/Lecture-14.pdf
 */
#define IRRIGATION_BUTTON_PORT GPIO_PORT_P5
#define IRRIGATION_BUTTON_PIN GPIO_PIN1
#define IRRIGATION_BUTTON_INTERRUPT_PORT INT_PORT5


/**
 * Contains hardware specific code:
 * - button initialization
 * - button interrupt handling
 */
void irrigation_button_hw_init(void);

/**
 * Interrupt handler for door button
 */
void PORT5_IRQHandler(void);

#endif
