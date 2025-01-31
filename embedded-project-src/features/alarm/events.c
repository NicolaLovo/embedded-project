#include "features/alarm/events.h"
#include "features/alarm/fsm.h"
#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/redLED/redLED.h"

// This function is called when is night (alarm is active) and a contact is
// detected
void alarm_event_onContact(void) {

  if (alarm_current_state == ALARM_STATE_ACTIVE) {
    alarm_current_state = ALARM_STATE_BUZZER_ACTIVE;
  }
}

// This function is called when the contact is no longer detected
void alarm_event_onContactEnd(void) {

  if (alarm_current_state == ALARM_STATE_BUZZER_ACTIVE) {
    alarm_current_state = ALARM_STATE_IDLE;
  }
}

// This function is called when day became night, and the alarm is activated
void alarm_event_skyDark(void) {

  if (alarm_current_state == ALARM_STATE_IDLE) {
    alarm_current_state = ALARM_STATE_ACTIVE;
  }
}

// This function is called when day became night, and the alarm is de-activated
void alarm_event_skyLight(void) {

  if (alarm_current_state == ALARM_STATE_ACTIVE) {
    alarm_current_state = ALARM_STATE_IDLE;
  }
}
