#ifndef __SERVO_HW_H__
#define __SERVO_HW_H__


#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


/**
 * Boosterpack servo J2.19 maps to Port 2.5
 */
#define SERVO_PORT GPIO_PORT_P2
#define SERVO_PIN GPIO_PIN5

/**
 * Contains hardware specific code:
 * - hardware initialization
 *
 * Connection at slide 6
 * https://didatticaonline.unitn.it/dol/pluginfile.php/1882808/mod_resource/content/0/Lecture-14.pdf
 *
 * Docs at page 6
 * https://didatticaonline.unitn.it/dol/pluginfile.php/1882809/mod_resource/content/0/BoosterPack.pdf
 */
void servo_hw_init(void);

void rotate_servo_angle(uint8_t angle);

#endif
