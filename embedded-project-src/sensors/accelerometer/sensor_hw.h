#ifndef __ACCELEROMETER_HW_H__
#define __ACCELEROMETER_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/**
 * Contains hardware specific code:
 * - accelerometer initialization
 * - accelerometer interrupt handling
 */
void accelerometer_hw_init(void);
void ADC14_IRQHandler(void);

#endif
