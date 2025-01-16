#include "sensor_on_read.h"
#include "sensors/light/sensor_hw.h"

#include "features/door/fsm.h"
#include "features/door/events.h"


void door_button_on_press(void) {

    if (door_current_state == DOOR_STATE_OPEN || door_current_state == DOOR_STATE_FORCE_OPEN) {
        door_event_button_close();
        return;
    }

    if (door_current_state == DOOR_STATE_CLOSE) {

        /**
         * If it is day, just open the door,
         * if it is night to prevent closing due to skyDark, force open door
         */
        bool is_day = light_is_day();

        if(is_day) {
            door_event_button_open();
        } else {
            door_event_button_force_open();
        }
        return;
    }

}
