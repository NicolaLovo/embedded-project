#include "features/door/events.h"
#include "features/door/fsm.h"



void door_event_skyDark(void) {
    switch(door_current_state) {
    case DOOR_STATE_CLOSE:
    case DOOR_STATE_FORCE_OPEN:
        return;
    case DOOR_STATE_OPEN:
        door_current_state = DOOR_STATE_CLOSE;
        return;
    }
}
void door_event_button_open(void){
    switch(door_current_state) {
    case DOOR_STATE_OPEN:
    case DOOR_STATE_FORCE_OPEN:
        return;
    case DOOR_STATE_CLOSE:
        door_current_state = DOOR_STATE_OPEN;
        return;
    }
}
void door_event_button_close(void) {
    switch(door_current_state) {
    case DOOR_STATE_CLOSE:
        return;
    case DOOR_STATE_FORCE_OPEN:
    case DOOR_STATE_OPEN:
        door_current_state = DOOR_STATE_CLOSE;
        return;
    }
}
void door_event_earthquake_start(void) {
    switch(door_current_state) {
    case DOOR_STATE_FORCE_OPEN:
        return;
    case DOOR_STATE_CLOSE:
    case DOOR_STATE_OPEN:
        door_current_state = DOOR_STATE_FORCE_OPEN;
        return;
    }
}
void door_event_earthquake_end(void) {
    switch(door_current_state) {
    case DOOR_STATE_FORCE_OPEN:
        door_current_state = DOOR_STATE_OPEN;
        return;
    case DOOR_STATE_CLOSE:
    case DOOR_STATE_OPEN:
        return;
    }
}
