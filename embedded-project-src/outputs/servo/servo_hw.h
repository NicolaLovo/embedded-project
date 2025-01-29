#ifndef __SERVO_HW_H__
#define __SERVO_HW_H__


#include <ti/devices/msp432p4xx/driverlib/driverlib.h>



/**
 * Boosterpack servo J2.19 maps to Port 2.5
 *
 * https://www.youtube.com/watch?v=UVyU2D-ZSBo
 */
#define SERVO_PORT GPIO_PORT_P2
#define SERVO_PIN GPIO_PIN5


// PWM configurations
#define PWM_FREQUENCY_HZ 50            // 50Hz = 20ms period

/**
 * Timer period for 50Hz
 */
#define TIMER_PERIOD ((SystemCoreClock / PWM_FREQUENCY_HZ) - 1) // Timer period for 50Hz

/**
 * 0.5ms pulse (about 2.5% duty cycle) -> 0° position
 */
#define SERVO_MIN_DUTY_CYCLE (TIMER_PERIOD * 2.5/100) 

/**
 * 5ms pulse (about 22% duty cycle) -> 180° position
 * 2.5ms pulse (12.5% duty cycle) -> 90° position
 * 1.5ms pulse (7.5% duty cycle) -> 45° position
 */
#define SERVO_MAX_DUTY_CYCLE (TIMER_PERIOD * 22/100) 




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

/**
 * 
 * This function takes an angle in degrees and rotates the servo motor to that angle.
 * 
 * @param angle The angle in degrees to which the servo should be rotated. 
 *              Valid values are from 0 to 180 degrees.
 */
void rotate_servo_angle(uint8_t angle);

#endif
