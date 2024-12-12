#include "features/irrigation/fsm.h"


void fn_irrigation_init(){
    // hardware init...
    irrigation_current_state = IRRIGATION_STATE_IDLE;
}
void fn_irrigation_idle(void){
    // timer not counting
}
void fn_irrigation_on(void){
    // ...
    // turn blue led on, while timer counting
    // ...
    // irrigation done
}

extern Irrigation_State_t irrigation_current_state = IRRIGATION_STATE_INIT;

Irrigation_StateMachine_t irrigation_fsm[] = {
    {IRRIGATION_STATE_INIT, fn_irrigation_init},
    {IRRIGATION_STATE_IDLE, fn_irrigation_idle},
    {IRRIGATION_STATE_IRRIGATE, fn_irrigation_on},
};
