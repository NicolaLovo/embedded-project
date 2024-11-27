#ifndef __IRRIGATION_FSM_H__
#define __IRRIGATION_FSM_H__

typedef enum {
    IRRIGATION_STATE_INIT,
    IRRIGATION_STATE_IDLE,
    IRRIGATION_STATE_IRRIGATE,
    //IRRIGATION_NUM_STATES
} Irrigation_State_t;


typedef struct {
    Irrigation_State_t state;
    void (*state_function)(void);
} Irrigation_StateMachine_t;

void fn_irrigation_init(void);
void fn_irrigation_idle(void);
void fn_irrigation_on(void);

extern Irrigation_State_t irrigation_current_state;
extern Irrigation_StateMachine_t irrigation_fsm[];

#endif
