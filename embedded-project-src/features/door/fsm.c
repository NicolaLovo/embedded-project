#include "features/door/fsm.h"



void fn_door_init(){
    // hardware init...
    //door_current_state = DOOR_STATE_CLOSE;

    door_current_state = DOOR_STATE_OPEN;
}

void fn_door_open(){

}

void fn_door_close(){

}

void fn_door_force_open(){
}

extern Door_State_t door_current_state = DOOR_STATE_INIT;

Door_StateMachine_t door_fsm[] = {
    {DOOR_STATE_INIT, fn_door_init},
    {DOOR_STATE_OPEN, fn_door_open},
    {DOOR_STATE_CLOSE, fn_door_close},
    {DOOR_STATE_FORCE_OPEN, fn_door_force_open}
};
