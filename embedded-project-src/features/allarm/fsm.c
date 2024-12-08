#include "features/allarm/fsm.h"

void fn_allarm_init() {
    // hardware init...
    allarm_current_state = ALLARM_STATE_IDLE;
}

void fn_allarm_idle() {

}

void fn_allarm_system_active() {

}

void fn_allarm_buzzer_active() {

}


extern Allarm_state_t allarm_current_state = ALLARM_STATE_INIT;


Allarm_stateMachine_t allarm_fsm[] = {
    {ALLARM_STATE_INIT, fn_allarm_init},
    {ALLARM_STATE_IDLE, fn_allarm_idle},
    {ALLARM_STATE_ACTIVE, fn_allarm_system_active},
    {ALLARM_STATE_BUZZER_ACTIVE, fn_allarm_buzzer_active}
};


