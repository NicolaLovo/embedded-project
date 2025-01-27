#include "features/irrigation/events.h"
#include "features/irrigation/fsm.h"
#include "outputs/blueLED/blueLED.h"

/*
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
*/

//  Called when the button for irrigation is pressed
void irrigation_event_button_pressed(void){
    switch (irrigation_current_state){
      case IRRIGATION_STATE_IDLE : {
        irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
        fn_irrigation_on();
        break;
      }
      case IRRIGATION_STATE_IRRIGATE : {
        irrigation_current_state = IRRIGATION_STATE_IDLE;
        fn_irrigation_idle();
        break;
      }
      case IRRIGATION_STATE_INIT : {
        irrigation_current_state = IRRIGATION_STATE_IRRIGATE;
        fn_irrigation_on();
        break;
      }
  }
}

