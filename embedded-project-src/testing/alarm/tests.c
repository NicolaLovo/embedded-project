#include "config.h"
#include "features/alarm/events.h"
#include "features/alarm/fsm.h"
#include <assert.h>
#include <stdio.h>

#ifdef TESTING

// Function to run the current state function of the alarm FSM
void run_allarm_fsm() {
  if (allarm_current_state < ALLARM_NUM_STATES) {
    (*allarm_fsm[allarm_current_state].state_function)();
  }
}

// Function to test the alarm feature
void test_allarm_feature() {
  // Initial state should be ALLARM_STATE_INIT
  assert(allarm_current_state == ALLARM_STATE_INIT);
  run_allarm_fsm();

  // After initialization, state should be ALLARM_STATE_IDLE
  assert(allarm_current_state == ALLARM_STATE_IDLE);
  run_allarm_fsm();

  // Simulate contact end event, state should remain ALLARM_STATE_IDLE
  allarm_event_onContactEnd();
  assert(allarm_current_state == ALLARM_STATE_IDLE);
  run_allarm_fsm();

  // Simulate sky dark event, state should change to ALLARM_STATE_ACTIVE
  allarm_event_skyDark();
  assert(allarm_current_state == ALLARM_STATE_ACTIVE);
  run_allarm_fsm();

  // Simulate contact event, state should change to ALLARM_STATE_BUZZER_ACTIVE
  allarm_event_onContact();
  assert(allarm_current_state == ALLARM_STATE_BUZZER_ACTIVE);
  run_allarm_fsm();

  // Simulate contact end event, state should remain ALLARM_STATE_IDLE
  allarm_event_onContactEnd();
  assert(allarm_current_state == ALLARM_STATE_IDLE);
  run_allarm_fsm();

  // Simulate sky light event, state should change back to ALLARM_STATE_IDLE
  allarm_event_skyLight();
  assert(allarm_current_state == ALLARM_STATE_IDLE);
  run_allarm_fsm();

  // Simulate contact event, state should change to ALLARM_STATE_BUZZER_ACTIVE
  allarm_event_onContact();
  assert(allarm_current_state == ALLARM_STATE_IDLE);
  run_allarm_fsm();

  printf("\nAllarm tests done successfully\n");
}

#else

#endif
