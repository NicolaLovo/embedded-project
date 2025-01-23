#include "features/climate/fsm.h"
#include "outputs/rgbLED/rgbLED.h"


void fn_climate_init(){
    climate_current_state=CLIMATE_STATE_OFF;
    rgb_set_off();
}
void fn_climate_radiator(){
    climate_current_state=CLIMATE_STATE_RADIATOR;
    rgb_set_red();
}

void fn_climate_off(){
    climate_current_state=CLIMATE_STATE_OFF;
    rgb_set_off();

}
void fn_climate_airconditioning(){
    climate_current_state=CLIMATE_STATE_AIRCONDITIONING;
    rgb_set_blue();

}

extern Climate_state climate_current_state = CLIMATE_STATE_INIT;


extern Climate_stateMachine climate_fsm[]={
    {CLIMATE_STATE_INIT,fn_climate_init},
    {CLIMATE_STATE_RADIATOR,fn_climate_radiator},
    {CLIMATE_STATE_OFF,fn_climate_off},
    {CLIMATE_STATE_AIRCONDITIONING,fn_climate_airconditioning}
};







/*
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
*/


