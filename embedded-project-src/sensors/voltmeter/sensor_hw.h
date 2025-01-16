#ifndef __VOLTMETER_HW_H__
#define __VOLTMETER_HW_H__

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


/**
 * The Voltmeter is mapped to port J4.34 on BoosterPack MKII
 * Then the port J4.34 is connected to the P2.3 on the MSP432P401R
 */
#define ALLIGATOR_CLIP_PORT GPIO_PORT_P2
#define ALLIGATOR_CLIP_PIN GPIO_PIN3

/**
 * Initialize the hardware for the voltage sensor
 */
void voltage_hw_init(void);

/**
 * Boolean function to check if the voltage is high
 * @return 1 if the voltage is high, 0 otherwise
 */
int voltage_is_high();

#endif
