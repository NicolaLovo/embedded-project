#include "features/alarm/events.h"
#include "features/alarm/fsm.h"
#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/redLED/redLED.h"

void alarm_event_onContact(void) {

  if (alarm_current_state == ALARM_STATE_ACTIVE) {
    alarm_current_state = ALARM_STATE_BUZZER_ACTIVE;
  }
  // printf("\nalarm_current_state: alarm_event_onContact");
}

void alarm_event_onContactEnd(void) {

  if (alarm_current_state == ALARM_STATE_BUZZER_ACTIVE) {
    alarm_current_state = ALARM_STATE_IDLE;
    // printf("\nalarm_current_state: alarm_event_onContactEnd");
  }
}

void alarm_event_skyDark(void) {

  if (alarm_current_state == ALARM_STATE_IDLE) {
    alarm_current_state = ALARM_STATE_ACTIVE;
    // printf("\nalarm_current_state:  alarm_event_skyDark");
  }
}

void alarm_event_skyLight(void) {

  if (alarm_current_state == ALARM_STATE_ACTIVE) {
    alarm_current_state = ALARM_STATE_IDLE;
    // printf("\nalarm_current_state:   alarm_event_skyLight");
  }
}
