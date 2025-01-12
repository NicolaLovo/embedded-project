#include "sensor_on_read.h"

#include "features/door/fsm.h"
#include "features/door/events.h"


void door_button_on_press(void) {

    if (door_current_state == DOOR_STATE_OPEN || door_current_state == DOOR_STATE_FORCE_OPEN) {
        door_event_button_close();
        return;
    }

    if (door_current_state == DOOR_STATE_CLOSE) {

        // if it is day, door_event_button_open()
        // if it is night, door_event_button_force_open()
        // define functions is_day() in sensor_on_read.c of light sensor

        door_event_button_open();
        return;
    }

}
