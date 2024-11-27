#ifndef FEATURES_RADIATOR_FSM_H_
#define FEATURES_RADIATOR_FSM_H_

#include "events.h"

typedef enum Temperature_State{
    OFF,
    RADIATOR_ON,
    AC_ON
}Temperature_State;

Temperature_State fn_climateSystem_init();
Temperature_State new_temperature_current_state(Temperature_State temperature_current_state, Temperature_Event temperature_event);



#endif
