#ifndef FEATURES_CLIMATE_FSM_H_
#define FEATURES_CLIMATE_FSM_H_

#include "events.h"

typedef enum {
    CLIMATE_STATE_RADIATOR_ON,
    CLIMATE_STATE_AIRCONDITIONING_ON,
    CLIMATE_STATE_SHUTOFF,
    CLIMATE_STATE_INIT
}Climate_state;

typedef struct Climate_state{
    Climate_state state;
    void(*state_function)(void);
}Climate_stateMachine;

void fn_climate_init(void);
void fn_climate_radiator(void);
void fn_climate_airconditioning(void);
void fn_climate_shutoff(void);

extern Climate_state climate_current_state;
extern Climate_stateMachine climate_fsm[];

#endif










/*typedef enum Temperature_State{
    OFF,
    RADIATOR_ON,
    AC_ON
}Temperature_State;


Temperature_State new_temperature_current_state(Temperature_State temperature_current_state, Temperature_Event temperature_event);*/




