#include "sensor_on_read.h"

#include "features/door/fsm.h"
#include "features/door/events.h"


void door_button_on_press(void) {

    if (door_current_state == DOOR_STATE_OPEN || door_current_state == DOOR_STATE_FORCE_OPEN) {
        door_event_button_close();
        return;
    }

    if (door_current_state == DOOR_STATE_CLOSE) {
        door_event_button_open();
        return;
    }

}
