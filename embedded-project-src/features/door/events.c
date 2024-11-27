#include "features/door/events.h"
#include "features/door/fsm.h"



void door_event_skyDark(void) {
    if (door_current_state == DOOR_STATE_OPEN) {
        door_current_state = DOOR_STATE_CLOSE;
        return;
    }
}

void door_event_button_open(void) {
    if (door_current_state == DOOR_STATE_CLOSE) {
        door_current_state = DOOR_STATE_OPEN;
        return;
    }
}

void door_event_button_close(void) {
    if (door_current_state == DOOR_STATE_FORCE_OPEN || door_current_state == DOOR_STATE_OPEN) {
        door_current_state = DOOR_STATE_CLOSE;
        return;
    }
}

void door_event_earthquake_start(void) {
    if (door_current_state == DOOR_STATE_CLOSE || door_current_state == DOOR_STATE_OPEN) {
        door_current_state = DOOR_STATE_FORCE_OPEN;
        return;
    }
}

void door_event_earthquake_end(void) {
    if (door_current_state == DOOR_STATE_FORCE_OPEN) {
        door_current_state = DOOR_STATE_OPEN;
        return;
    }
}
