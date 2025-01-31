#ifndef __CLIMATE_FSM_H__
#define __CLIMATE_FSM_H__

//state in whitch the fsm can be 
typedef enum{
    CLIMATE_STATE_INIT,
    CLIMATE_STATE_RADIATOR,
    CLIMATE_STATE_OFF,
    CLIMATE_STATE_AIRCONDITIONING,
    CLIMATE_NUM_STATES
}Climate_state;

// struct of state machine which associates states with their functions 
typedef struct {
    Climate_state state;
    void(*state_function)(void);
}Climate_stateMachine;

void fn_climate_init(void);
void fn_climate_radiator(void);
void fn_climate_off(void);
void fn_climate_airconditioning(void);

extern Climate_state climate_current_state;
extern Climate_stateMachine climate_fsm[];

#endif










/*typedef enum Temperature_State{
    OFF,
    RADIATOR_ON,
    AC_ON
}Temperature_State;


Temperature_State new_temperature_current_state(Temperature_State temperature_current_state, Temperature_Event temperature_event);*/




