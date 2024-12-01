#include "fsm.h"
#include "events.h"

void allarm_event_onContact(void){

    if (allarm_current_state == ALLARM_STATE_ACTIVE){
        allarm_current_state = ALLARM_STATE_BUZZER_ACTIVE;
    }
}

void allarm_event_onContactEnd(void){

    if (allarm_current_state == ALLARM_STATE_BUZZER_ACTIVE){
        allarm_current_state = ALLARM_STATE_IDLE;
    }
}

void allarm_event_skyDark(void){

    if (allarm_current_state == ALLARM_STATE_IDLE){
        allarm_current_state = ALLARM_STATE_ACTIVE;
    }
}

void allarm_event_skyLight(void){
    
    if (allarm_current_state == ALLARM_STATE_ACTIVE){
        allarm_current_state = ALLARM_STATE_IDLE;
    }
}
