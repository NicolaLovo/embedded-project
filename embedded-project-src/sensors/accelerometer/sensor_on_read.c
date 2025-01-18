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

    static int stabilityCounter = 0;
    //static EarthquakeState state = IDLE;
    /* Check for significant movement */
            bool significantMovement = (x > HIGH_THRSD || y > HIGH_THRSD || z > HIGH_THRSD) ||
                                       (x < LOW_THRSD || y < LOW_THRSD || z < LOW_THRSD);

            switch (state)
            {
            case IDLE:
                if (significantMovement) {
                    state = ACTIVE;
                    stabilityCounter = 0;
                    printf("\n--- EARTHQUAKE START detected ---\n");
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
                        printf("--- EARTHQUAKE END detected ---\n");
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
bool earthquake_active(){
  switch(state){
     case IDLE: return false;
     case ACTIVE: return true;
     case STABILIZING: return true;
  }
  return false;
}
