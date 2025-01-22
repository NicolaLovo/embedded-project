#include "features/alarm/fsm.h"
#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/redLED/redLED.h"

void fn_alarm_init() {
  // hardware init...
  // printf("fn_alarm_init: Alarm is initialized\n");
  alarm_current_state = ALARM_STATE_IDLE;
  // red_toggle_led(true);
  red_toggle_led(false);
}

void fn_alarm_idle() {
  // printf("fn_alarm_idle: Alarm is idle\n");
  buzzer_off();
  red_toggle_led(false);
}

void fn_alarm_system_active() {
  // printf("fn_alarm_system_active: Alarm is active\n");
  buzzer_off();
  red_toggle_led(false);
}

void fn_alarm_buzzer_active() {
  red_toggle_led(true);
  // printf("fn_alarm_buzzer_active: Buzzer is active\n");
  buzzer_on();
}

extern Alarm_state_t alarm_current_state = ALARM_STATE_INIT;

Alarm_stateMachine_t alarm_fsm[] = {
    {ALARM_STATE_INIT, fn_alarm_init},
    {ALARM_STATE_IDLE, fn_alarm_idle},
    {ALARM_STATE_ACTIVE, fn_alarm_system_active},
    {ALARM_STATE_BUZZER_ACTIVE, fn_alarm_buzzer_active}};
