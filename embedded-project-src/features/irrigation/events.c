#include "features/irrigation/events.h"
#include "features/irrigation/fsm.h"


// Called when temp sensor is high (above a threshold)
void irrigation_event_highTemp(void){
    switch (irrigation_current_state) {
        case IRRIGATION_STATE_IDLE:
        case IRRIGATION_STATE_INIT:
        case IRRIGATION_STATE_IRRIGATE:
          irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
    }
}

// Called when temp sensor is low (under a threshold)
void irrigation_event_lowTemp(void){
    switch (irrigation_current_state) {
        case IRRIGATION_STATE_IDLE:
        case IRRIGATION_STATE_INIT:
        case IRRIGATION_STATE_IRRIGATE:
          irrigation_current_state = IRRIGATION_STATE_IDLE;
    }
}

// Called when the irrigation is on
void irrigation_event_timer_count(void){
    switch (irrigation_current_state) {
        case IRRIGATION_STATE_IDLE:
        case IRRIGATION_STATE_INIT:
        case IRRIGATION_STATE_IRRIGATE:
          irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
    }
}

// Called when the timer reaches a specified number
void irrigation_event_timer_done(void){
    switch (irrigation_current_state) {
        case IRRIGATION_STATE_IDLE:
        case IRRIGATION_STATE_INIT:
        case IRRIGATION_STATE_IRRIGATE:
          irrigation_current_state = IRRIGATION_STATE_IDLE;
    }
}

//  Called when the button for irrigation activation is pressed
void irrigation_event_button_on(void){
    switch (irrigation_current_state) {
        case IRRIGATION_STATE_IDLE:
        case IRRIGATION_STATE_INIT:
        case IRRIGATION_STATE_IRRIGATE:
          irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
    }
}

// Called when the button for irrigation ending is pressed
void irrigation_event_button_off(void){
    switch (irrigation_current_state) {
        case IRRIGATION_STATE_IDLE:
        case IRRIGATION_STATE_INIT:
        case IRRIGATION_STATE_IRRIGATE:
          irrigation_current_state = IRRIGATION_STATE_IDLE;
    }
}
