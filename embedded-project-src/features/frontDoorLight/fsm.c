#include "fsm.h"

void fn_front_light_door_init(){
    // hardware init...
    front_door_current_state = FRONT_DOOR_LIGHT_STATE_OFF;
}

void fn_front_light_door_lights_off(){

}

void fn_front_light_door_lights_on(){

}

Front_door_light_stateMachine_t front_door_fsm[] = {
    {FRONT_DOOR_LIGHT_STATE_INIT, fn_front_light_door_init},
    {FRONT_DOOR_LIGHT_STATE_ON, fn_front_light_door_lights_on},
    {FRONT_DOOR_LIGHT_STATE_OFF, fn_front_light_door_lights_off}
};

extern Front_light_door_state_t front_door_current_state = FRONT_DOOR_LIGHT_STATE_INIT;



