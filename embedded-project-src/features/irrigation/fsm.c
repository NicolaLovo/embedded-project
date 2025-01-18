#include "features/irrigation/fsm.h"
#include "outputs/blueLED/blueLED.h"


void fn_irrigation_init(){
    // hardware init
    // Initialize blueLED
    blue_toggle_led(false);
    irrigation_current_state = IRRIGATION_STATE_IDLE;
}
void fn_irrigation_idle(void){
    // timer not counting
    blue_toggle_led(false);
}
void fn_irrigation_on(void){
    // ...
    // turn blue led on, while timer counting
    // ...
    blue_toggle_led(true);
}

extern Irrigation_State_t irrigation_current_state = IRRIGATION_STATE_INIT;

Irrigation_StateMachine_t irrigation_fsm[] = {
    {IRRIGATION_STATE_INIT, fn_irrigation_init},
    {IRRIGATION_STATE_IDLE, fn_irrigation_idle},
    {IRRIGATION_STATE_IRRIGATE, fn_irrigation_on},
};
