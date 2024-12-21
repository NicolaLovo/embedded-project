#ifndef __ACCELEROMETER_ON_READ_H__
#define __ACCELEROMETER_ON_READ_H__

/* MCU Facing: */
// UP: X = 8300, Y = 8000, Z = 11500
// DOWN: X = 8500, Y = 8600, Z = 4900
// LEFT: X = 4900, Y = 8100, Z = 8600
// RIGHT: X = 11500, Y = 8100, Z = 7800
// FRONT: X = 8500, Y = 4900, Z = 8100
// BACK: X = 8500, Y = 11500, Z = 8600

/* Movement thresholds */
#define HIGH_THRSD      14000
#define LOW_THRSD       4000

/**
 * Hw-independent function to be called by the accelerometer isr
 * Calls accordingly the events to mutate the fsm of the features
 */
void accelerometer_on_read(uint16_t resultsBuffer[3]);

#endif
