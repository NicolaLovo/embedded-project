#include "events.h"
#include "fsm.h"

void front_door_light_event_skyDark(void){

    if (front_door_current_state == FRONT_DOOR_LIGHT_STATE_OFF){
        front_door_current_state = FRONT_DOOR_LIGHT_STATE_ON;
    }
}

void front_door_light_event_skyLight(void){

    if (front_door_current_state == FRONT_DOOR_LIGHT_STATE_ON){
        front_door_current_state = FRONT_DOOR_LIGHT_STATE_OFF;
    }
}
