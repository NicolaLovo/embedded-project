#include "config.h"
#include "features/alarm/events.h"
#include "features/alarm/fsm.h"
#include <assert.h>
#include <stdio.h>

#ifdef TESTING

// Function to run the current state function of the alarm FSM
void run_alarm_fsm() {
  if (alarm_current_state < ALARM_NUM_STATES) {
    (*alarm_fsm[alarm_current_state].state_function)();
  }
}

// Function to test the alarm feature
void test_alarm_feature() {
  // Initial state should be ALARM_STATE_INIT
  assert(alarm_current_state == ALARM_STATE_INIT);
  run_alarm_fsm();

  // After initialization, state should be ALARM_STATE_IDLE
  assert(alarm_current_state == ALARM_STATE_IDLE);
  run_alarm_fsm();

  // Simulate contact end event, state should remain ALARM_STATE_IDLE
  alarm_event_onContactEnd();
  assert(alarm_current_state == ALARM_STATE_IDLE);
  run_alarm_fsm();

  // Simulate sky dark event, state should change to ALARM_STATE_ACTIVE
  alarm_event_skyDark();
  assert(alarm_current_state == ALARM_STATE_ACTIVE);
  run_alarm_fsm();

  // Simulate contact event, state should change to ALARM_STATE_BUZZER_ACTIVE
  alarm_event_onContact();
  assert(alarm_current_state == ALARM_STATE_BUZZER_ACTIVE);
  run_alarm_fsm();

  // Simulate contact end event, state should remain ALARM_STATE_IDLE
  alarm_event_onContactEnd();
  assert(alarm_current_state == ALARM_STATE_IDLE);
  run_alarm_fsm();

  // Simulate sky light event, state should change back to ALARM_STATE_IDLE
  alarm_event_skyLight();
  assert(alarm_current_state == ALARM_STATE_IDLE);
  run_alarm_fsm();

  // Simulate contact event, state should change to ALARM_STATE_BUZZER_ACTIVE
  alarm_event_onContact();
  assert(alarm_current_state == ALARM_STATE_IDLE);
  run_alarm_fsm();

  printf("\nAlarm tests done successfully\n");
}

#else

#endif
