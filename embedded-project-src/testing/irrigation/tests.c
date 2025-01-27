#include "config.h"
#include "features/irrigation/events.h"
#include "features/irrigation/fsm.h"
#include <assert.h>

#ifdef TESTING

/**
 * Run the current irrigation
    fsm function
 */
void run_irrigation_fsm() {
  if (irrigation_current_state < IRRIGATION_NUM_STATES) {
    (*irrigation_fsm[irrigation_current_state].state_function)();
  }
}

void test_irrigation_feature() {
  /**
   * verify irrigation is initialized
   */
  assert(irrigation_current_state == IRRIGATION_STATE_INIT);
  run_irrigation_fsm();

  /**
   * verify irrigation is idle after being initialized
   */
  assert(irrigation_current_state == IRRIGATION_STATE_IDLE);
  run_irrigation_fsm();

  /**
   * trigger event: button pressed -> expect irrigation state 'irrigate'
   */
  irrigation_event_button_pressed();
  assert(irrigation_current_state == IRRIGATION_STATE_IRRIGATE);
  run_irrigation_fsm();

  /**
   * trigger event: button pressed -> expect irrigation state 'idle'
   */
  irrigation_event_button_pressed();
  assert(irrigation_current_state == IRRIGATION_STATE_IDLE);
  run_irrigation_fsm();

  printf("irrigation tests done successully\n");
}

#else

#endif
