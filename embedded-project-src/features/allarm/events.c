#include "fsm.h"
#include "events.h"

void allarm_event_onContact(void) {
    switch (allarm_current_state) {
    case ALLARM_STATE_IDLE:
    case ALLARM_STATE_INIT:
    case ALLARM_STATE_BUZZER_ACTIVE:
    case ALLARM_STATE_ACTIVE:
        allarm_current_state = ALLARM_STATE_BUZZER_ACTIVE;
        return;
    }
}

void allarm_event_onContactEnd(void) {
    switch (allarm_current_state) {


    case ALLARM_STATE_ACTIVE:
    case ALLARM_STATE_INIT:
    case ALLARM_STATE_IDLE:
    case ALLARM_STATE_BUZZER_ACTIVE:
        allarm_current_state = ALLARM_STATE_IDLE;
        return;
    }
}

void allarm_event_skyDark(void) {
    switch (allarm_current_state) {

    case ALLARM_STATE_ACTIVE:
    case ALLARM_STATE_INIT:
    case ALLARM_STATE_BUZZER_ACTIVE:
    case ALLARM_STATE_IDLE:
        return allarm_current_state = ALLARM_STATE_ACTIVE;
    }
}

void allarm_event_skyLight(void) {
    switch (allarm_current_state) {
    case ALLARM_STATE_IDLE:
    case ALLARM_STATE_INIT:
    case ALLARM_STATE_BUZZER_ACTIVE:
    case ALLARM_STATE_ACTIVE:
        return allarm_current_state = ALLARM_STATE_IDLE;
    }
}




