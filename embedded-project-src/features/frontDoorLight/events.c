#include "events.h"
#include "fsm.h"

void front_door_light_event_skyDark(void) {

    switch(front_door_current_state) {
        case FRONT_DOOR_LIGHT_STATE_OFF:
            front_door_current_state = FRONT_DOOR_LIGHT_STATE_ON;
            return;
        case FRONT_DOOR_LIGHT_STATE_ON:
        case FRONT_DOOR_LIGHT_STATE_INIT:
        case FRONT_DOOR_LIGHT_NUM_STATES:
            return;
    }

}

void front_door_light_event_skyLight(void) {

    switch(front_door_current_state) {
        case FRONT_DOOR_LIGHT_STATE_ON:
            front_door_current_state = FRONT_DOOR_LIGHT_STATE_OFF;
            return;
        case FRONT_DOOR_LIGHT_STATE_OFF:
        case FRONT_DOOR_LIGHT_STATE_INIT:
        case FRONT_DOOR_LIGHT_NUM_STATES:
            return;
        }
        
}