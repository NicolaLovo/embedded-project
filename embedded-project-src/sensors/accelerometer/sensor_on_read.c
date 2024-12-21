#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "sensor_on_read.h"
#include "features/door/fsm.h"
#include "features/door/events.h"


void accelerometer_on_read(uint16_t resultsBuffer[3]) {

    uint16_t x = resultsBuffer[0];
    uint16_t y = resultsBuffer[1];
    uint16_t z = resultsBuffer[2];

    /* Defining the conditions for earthquake in each direction */
    bool over_high_thrsd = x > HIGH_THRSD || y > HIGH_THRSD || z > HIGH_THRSD;
    bool under_low_thrsd = x < LOW_THRSD  || y < LOW_THRSD  || z < LOW_THRSD;


    if (over_high_thrsd || under_low_thrsd){
        printf("--- EARTHQUAKE detected ---");
        //printf("X: %u, Y: %u, Z: %u\n", resultsBuffer[0], resultsBuffer[1], resultsBuffer[2]);
        if (door_current_state == DOOR_STATE_CLOSE) {
            door_event_earthquake_start();
            return;
        }
        _delay_cycles(5000000);
    }
}
