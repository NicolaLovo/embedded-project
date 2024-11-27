#include "features/irrigation/fsm.h"


void fn_irrigation_init(){
    // hardware init...
    irrigation_current_state = IRRIGATION_STATE_IDLE;
}
void fn_irrigation_idle(void){

}
void fn_irrigation_on(void){
    // hardware init... turn blue led on, timer counting
}

extern Irrigation_State_t irrigation_current_state = IRRIGATION_STATE_INIT;

Irrigation_StateMachine_t irrigation_fsm[] = {
    {IRRIGATION_STATE_INIT, fn_irrigation_init},
    {IRRIGATION_STATE_IDLE, fn_irrigation_idle},
    {IRRIGATION_STATE_IRRIGATE, fn_irrigation_on},
};
