#ifndef __ACCELEROMETER_ON_READ_H__
#define __ACCELEROMETER_ON_READ_H__

/* Movement thresholds */
#define HIGH_THRSD      14000
#define LOW_THRSD       4000

/* Stability parameter */
#define STABILITY_COUNT 800

/* State variables */
typedef enum {
    IDLE,       // No earthquake detected
    ACTIVE,     // Earthquake
    STABILIZING // Waiting for stabilization
} EarthquakeState;

/**
 * Hw-independent function to be called by the accelerometer isr
 * Calls accordingly the events to mutate the fsm of the features
 */
void accelerometer_on_read(uint16_t resultsBuffer[3]);

#endif
