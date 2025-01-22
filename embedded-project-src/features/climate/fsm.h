#ifndef FEATURES_FSM_H_
#define FEATURES_FSM_H_

typedef enum{
    CLIMATE_STATE_INIT,
    CLIMATE_STATE_RADIATOR,
    CLIMATE_STATE_OFF,
    CLIMATE_STATE_AIRCONDITIONING,
    CLIMATE_NUM_STATES
}Climate_state;

typedef struct {
    Climate_state state;
    void(*state_function)(void);
}Climate_stateMachine;

void fn_climate_init(void);
void fn_climate_radiator(void);
void fn_climate_off(void);
void fn_climate_airconditioning(void);

 Climate_state climate_current_state;
 Climate_stateMachine climate_fsm[];

#endif










/*typedef enum Temperature_State{
    OFF,
    RADIATOR_ON,
    AC_ON
}Temperature_State;


Temperature_State new_temperature_current_state(Temperature_State temperature_current_state, Temperature_Event temperature_event);*/




