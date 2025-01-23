#include "config.h"
#include "features/climate/events.h"
#include "features/climate/fsm.h"
#include <assert.h>

#ifdef TESTING

/**
 * Run the current irrigation
    fsm function
 */
void run_climate_fsm() {
  if (climate_current_state < CLIMATE_NUM_STATES) {
    (*climate_fsm[climate_current_state].state_function)();
  }
}

void test_climate_feature() {
  /**
   * verify irrigationis initialized
   */
  assert(climate_current_state == CLIMATE_STATE_INIT);
  run_climate_fsm();

  climate_on_under_low();
  assert(climate_current_state == CLIMATE_STATE_RADIATOR);
  run_climate_fsm();

  climate_on_above_idle();
  assert(climate_current_state == CLIMATE_STATE_OFF);
  run_climate_fsm();

  climate_on_above_high();
  assert(climate_current_state == CLIMATE_STATE_AIRCONDITIONING);
  run_climate_fsm();


  climate_on_under_idle();
  assert(climate_current_state == CLIMATE_STATE_OFF);
  run_climate_fsm();

  printf("climate tests done successully\n");
}

#else

#endif
