#ifndef __ACCELEROMETER_ON_READ_H__
#define __ACCELEROMETER_ON_READ_H__

/* Movement thresholds */
#define UP_THRESHOLD         13000
#define DOWN_THRESHOLD       9000

#define LEFT_THRESHOLD       6000
#define RIGHT_THRESHOLD      11000

#define FORWARD_THRESHOLD    12000
#define BACKWARD_THRESHOLD   6000

/**
 * Hw-independent function to be called by the accelerometer isr
 * Calls accordingly the events to mutate the fsm of the features
 */
void accelerometer_on_read(uint16_t resultsBuffer[3]);

#endif
