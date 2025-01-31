#include "features/alarm/fsm.h"
#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/redLED/redLED.h"

//  Function to initialize the alarm state machine, it sets the current state to
//  idle and turns off the red led
void fn_alarm_init() {
  alarm_current_state = ALARM_STATE_IDLE;
  red_toggle_led(false);
}

// Function to set the alarm state to idle, turn off the buzzer and the red led
void fn_alarm_idle() {
  buzzer_off();
  red_toggle_led(false);
}

// Function to set the alarm state active, turn off the buzzer and the red led
void fn_alarm_system_active() {
  buzzer_off();
  red_toggle_led(false);
}

// Function to set the alarm state to buzzer active, turn on the buzzer and the
// red led
void fn_alarm_buzzer_active() {
  red_toggle_led(true);
  buzzer_on();
}

// Variable to store the current state of the alarm state machine
extern Alarm_state_t alarm_current_state = ALARM_STATE_INIT;

// Array of structures to store the alarm state machine
Alarm_stateMachine_t alarm_fsm[] = {
    {ALARM_STATE_INIT, fn_alarm_init},
    {ALARM_STATE_IDLE, fn_alarm_idle},
    {ALARM_STATE_ACTIVE, fn_alarm_system_active},
    {ALARM_STATE_BUZZER_ACTIVE, fn_alarm_buzzer_active}};
