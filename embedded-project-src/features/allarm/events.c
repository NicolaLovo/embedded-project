#include "features/allarm/events.h"
#include "features/allarm/fsm.h"
#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/redLED/redLED.h"

void allarm_event_onContact(void) {

  if (allarm_current_state == ALLARM_STATE_ACTIVE) {
    allarm_current_state = ALLARM_STATE_BUZZER_ACTIVE;
  }
  // printf("\nallarm_current_state: allarm_event_onContact");
}

void allarm_event_onContactEnd(void) {

  if (allarm_current_state == ALLARM_STATE_BUZZER_ACTIVE) {
    allarm_current_state = ALLARM_STATE_IDLE;
    // printf("\nallarm_current_state: allarm_event_onContactEnd");
  }
}

void allarm_event_skyDark(void) {

  if (allarm_current_state == ALLARM_STATE_IDLE) {
    allarm_current_state = ALLARM_STATE_ACTIVE;
    // printf("\nallarm_current_state:  allarm_event_skyDark");
  }
}

void allarm_event_skyLight(void) {

  if (allarm_current_state == ALLARM_STATE_ACTIVE) {
    allarm_current_state = ALLARM_STATE_IDLE;
    // printf("\nallarm_current_state:   allarm_event_skyLight");
  }
}
