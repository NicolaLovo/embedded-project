#ifndef __ALARM_FSM_H__
#define __ALARM_FSM_H__

typedef enum {
    ALARM_STATE_INIT,
    ALARM_STATE_IDLE,
    ALARM_STATE_ACTIVE,
    ALARM_STATE_BUZZER_ACTIVE,
    ALARM_NUM_STATES
} Alarm_state_t;

typedef struct {
    Alarm_state_t state;
    void (*state_function)(void);
} Alarm_stateMachine_t;

void fn_alarm_init(void);
void fn_alarm_idle(void);
void fn_alarm_system_active(void);
void fn_alarm_buzzer_active(void);

extern Alarm_state_t alarm_current_state;
extern Alarm_stateMachine_t alarm_fsm[];


#endif
