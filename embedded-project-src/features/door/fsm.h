#ifndef __DOOR_FSM_H__
#define __DOOR_FSM_H__

typedef enum {
    DOOR_STATE_INIT,
    DOOR_STATE_OPEN,
    DOOR_STATE_CLOSE,
    DOOR_STATE_FORCE_OPEN,
    DOOR_NUM_STATES
} Door_State_t;


typedef struct {
    Door_State_t state;
    void (*state_function)(void);
} Door_StateMachine_t;


/**
 * Configure door-specific hardware
 *
 * Note that sensors hardware is configured in the sensors' specific file
 */
void fn_door_init(void);
void fn_door_open(void);
void fn_door_close(void);
void fn_door_force_open(void);

extern Door_State_t door_current_state;
extern Door_StateMachine_t door_fsm[];

#endif
