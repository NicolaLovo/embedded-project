#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "sensor_on_read.h"
#include "features/door/fsm.h"
#include "features/door/events.h"


void accelerometer_on_read(uint16_t resultsBuffer[3]) {
    /* Check if earthquake was detected */
    bool movement_detected = resultsBuffer[2] > UP_THRESHOLD || resultsBuffer[2] < DOWN_THRESHOLD ||
                             resultsBuffer[0] < LEFT_THRESHOLD || resultsBuffer[0] > RIGHT_THRESHOLD ||
                             resultsBuffer[1] > FORWARD_THRESHOLD || resultsBuffer[1] < BACKWARD_THRESHOLD;
    if(movement_detected){
        printf("--- earthquake detected!!! ---\n");
        if (door_current_state == DOOR_STATE_CLOSE) {
               door_event_earthquake_start();
               return;
        }
        _delay_cycles(5000000);
    }
}
