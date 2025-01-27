#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "sensor_on_read.h"
#include "features/door/fsm.h"
#include "features/door/events.h"

volatile extern EarthquakeState state = IDLE;

void accelerometer_on_read(uint16_t resultsBuffer[3]) {
    uint16_t x = resultsBuffer[0];
    uint16_t y = resultsBuffer[1];
    uint16_t z = resultsBuffer[2];

    // a static variable inside a function keeps its value between invocations
    static int stabilityCounter = 0;

    /* Check for significant movement */
    bool significantMovement = (x > HIGH_THRSD || y > HIGH_THRSD || z > HIGH_THRSD) ||
                                       (x < LOW_THRSD || y < LOW_THRSD || z < LOW_THRSD);

    switch (state){
        case IDLE:
           if (significantMovement) {
              state = ACTIVE;
              stabilityCounter = 0;
              //printf("X: %u, Y: %u, Z: %u\n", x, y, z);

              /* Trigger door event */
              door_event_earthquake_start();
            }
            break;
        case ACTIVE:
           if (significantMovement) {
               stabilityCounter = 0; // Reset stability counter if detecting activity
           } else {
               stabilityCounter++;
               if (stabilityCounter >= STABILITY_COUNT) {
                  state = STABILIZING;
                  stabilityCounter = 0;
                  /* Trigger door event */
                  door_event_earthquake_end();
               }
           }
           break;

        case STABILIZING:
          stabilityCounter++;
          if (stabilityCounter >= STABILITY_COUNT) {
            state = IDLE; // Ready to detect new earthquake
            }
          break;
        }

}
// function used by LCD to display whether there's an earthquake
bool earthquake_active(){
  switch(state){
     case IDLE: return false;         // no earthquake
     case ACTIVE: return true;        // earthquake
     case STABILIZING: return true;   // earthquake
  }
  return false;
}
