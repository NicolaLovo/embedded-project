#include "features/irrigation/events.h"
#include "features/irrigation/fsm.h"
#include "outputs/blueLED/blueLED.h"


// Called when temp sensor is high (above a threshold)
void irrigation_event_highTemp(void){
    if (irrigation_current_state != IRRIGATION_STATE_IRRIGATE){
        irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
        fn_irrigation_on();
    }

}

// Called when temp sensor is low (under a threshold)
void irrigation_event_lowTemp(void){
    irrigation_current_state = IRRIGATION_STATE_IDLE;
    fn_irrigation_idle();
}

//
// Probabilmente non serve, timer_start() da chiamare nelle funzioni
// che iniziano l'irrigazione (se evento precedente !0 IRRIGATE)
//
void irrigation_event_timer_start(void){
    if (irrigation_current_state != IRRIGATION_STATE_IRRIGATE){
        irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
    }

}

// Called when the timer reaches a specified number
void irrigation_event_timer_done(void){
    irrigation_current_state = IRRIGATION_STATE_IDLE;
    fn_irrigation_idle();
}

//  Called when the button for irrigation activation is pressed
void irrigation_event_button_on(void){
    if (irrigation_current_state != IRRIGATION_STATE_IRRIGATE){
        irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
        fn_irrigation_on();
    }
}

// Called when the button for irrigation ending is pressed
void irrigation_event_button_off(void){
    irrigation_current_state = IRRIGATION_STATE_IDLE;
    fn_irrigation_idle();
}
