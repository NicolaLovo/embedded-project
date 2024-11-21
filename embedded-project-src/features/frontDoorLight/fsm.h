#ifndef __FRONT_DOOR_LIGHT_FSM_H__
#define __FRONT_DOOR_LIGHT_FSM_H__

typedef enum {
    FRONT_DOOR_LIGHT_STATE_INIT,
    FRONT_DOOR_LIGHT_STATE_ON,
    FRONT_DOOR_LIGHT_STATE_OFF,
    FRONT_DOOR_LIGHT_NUM_STATES
} Front_light_door_state_t;


typedef struct{
    Front_light_door_state_t state;
    void (*state_function)(void);
} Front_door_light_stateMachine_t;

void fn_front_light_door_init(void);
void fn_front_light_door_lights_off(void);
void fn_front_light_door_lights_on(void);

extern Front_light_door_state_t front_door_current_state;
extern Front_door_light_stateMachine_t front_door_fsm[];


#endif