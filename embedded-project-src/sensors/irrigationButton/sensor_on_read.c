#include "sensor_on_read.h"

#include "features/irrigation/fsm.h"
#include "features/irrigation/events.h"


void irrigation_button_on_press(void) {

    // if irrigation is off, turn on
    if (irrigation_current_state != IRRIGATION_STATE_IRRIGATE){
        irrigation_event_button_on();
        return;
    } else { // if irrigation is on, turn off
        irrigation_event_button_off();
        return;
    }

}
