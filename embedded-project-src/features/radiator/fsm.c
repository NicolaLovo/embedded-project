#include "features/radiator/fsm.h"


Temperature_State fn_climateSystem_init(){
    return OFF;
}
Temperature_State new_temperature_current_state(Temperature_State temperature_current_state, Temperature_Event temperature_event){
    switch (temperature_current_state)
    {
        case OFF:
            if(temperature_event==LOW_TEMPERATURE){
                return RADIATOR_ON;
            }else if(temperature_event==HIGH_TEMPERATURE){
                return AC_ON;
            }
            break;
        case RADIATOR_ON:
            if(temperature_event==TURNOFF_TEMPERATURE){
                return OFF;
            }
            break;
        case AC_ON:
            if(temperature_event==TURNOFF_TEMPERATURE){
                return OFF;
            }
            break;
        
        default:
            break;
    }
}


