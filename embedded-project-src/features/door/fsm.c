#include "features/door/fsm.h"
#include "outputs/servo/servo_hw.h"


void fn_door_init(){
    // hardware init...
    //door_current_state = DOOR_STATE_CLOSE;

    door_current_state = DOOR_STATE_OPEN;
}

void fn_door_open(){
    rotate_servo_angle(90);
}

void fn_door_close(){
    rotate_servo_angle(0);
}

void fn_door_force_open(){
    rotate_servo_angle(90)
}

extern Door_State_t door_current_state = DOOR_STATE_INIT;

Door_StateMachine_t door_fsm[] = {
    {DOOR_STATE_INIT, fn_door_init},
    {DOOR_STATE_OPEN, fn_door_open},
    {DOOR_STATE_CLOSE, fn_door_close},
    {DOOR_STATE_FORCE_OPEN, fn_door_force_open}
};
