#ifndef __DOOR_BUTTON_HW_H__
#define __DOOR_BUTTON_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>



/**
 * Boosterpack S2 button J4.32 maps to Port 3.5
 * Slide 6
 * https://didatticaonline.unitn.it/dol/pluginfile.php/1882808/mod_resource/content/0/Lecture-14.pdf
 */
#define DOOR_BUTTON_PORT GPIO_PORT_P3
#define DOOR_BUTTON_PIN GPIO_PIN5
#define DOOR_BUTTON_INTERRUPT_PORT INT_PORT3


/**
 * Contains hardware specific code:
 * - button initialization
 * - button interrupt handling
 */
void door_button_hw_init(void);

/**
 * Interrupt handler for door button
 */
void PORT3_IRQHandler(void);

#endif
