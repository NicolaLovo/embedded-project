#include "features/allarm/fsm.h"
#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/redLED/redLED.h"

void fn_allarm_init() {
  // hardware init...
  // printf("fn_allarm_init: Allarm is initialized\n");
  allarm_current_state = ALLARM_STATE_IDLE;
  // red_toggle_led(true);
  red_toggle_led(false);
}

void fn_allarm_idle() {
  // printf("fn_allarm_idle: Allarm is idle\n");
  buzzer_off();
  red_toggle_led(false);
}

void fn_allarm_system_active() {
  // printf("fn_allarm_system_active: Allarm is active\n");
  buzzer_off();
  red_toggle_led(false);
}

void fn_allarm_buzzer_active() {
  red_toggle_led(true);
  // printf("fn_allarm_buzzer_active: Buzzer is active\n");
  buzzer_on();
}

extern Allarm_state_t allarm_current_state = ALLARM_STATE_INIT;

Allarm_stateMachine_t allarm_fsm[] = {
    {ALLARM_STATE_INIT, fn_allarm_init},
    {ALLARM_STATE_IDLE, fn_allarm_idle},
    {ALLARM_STATE_ACTIVE, fn_allarm_system_active},
    {ALLARM_STATE_BUZZER_ACTIVE, fn_allarm_buzzer_active}};
