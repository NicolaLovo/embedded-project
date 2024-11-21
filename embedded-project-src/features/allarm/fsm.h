#ifndef __ALLARM_FSM_H__
#define __ALLARM_FSM_H__

typedef enum {
    ALLARM_STATE_INIT,
    ALLARM_STATE_IDLE,
    ALLARM_STATE_ACTIVE,
    ALLARM_STATE_BUZZER_ACTIVE,
    ALLARM_NUM_STATES
} Allarm_state_t;

typedef struct {
    Allarm_state_t state;
    void (*state_function)(void);
} Allarm_stateMachine_t;

void fn_allarm_init(void);
void fn_allarm_idle(void);
void fn_allarm_system_active(void);
void fn_allarm_buzzer_active(void);

extern Allarm_state_t allarm_current_state;
extern Allarm_stateMachine_t allarm_fsm[];


#endif __ALLARM_FSM_H__