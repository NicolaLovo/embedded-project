#include "features/climate/events.h"
#include "features/climate/fsm.h"




void climate_event_highTemperature(void){
    switch (climate_current_state)
    {
    case CLIMATE_STATE_RADIATOR_ON:
        
    case CLIMATE_STATE_AIRCONDITIONING_ON:
        
    case CLIMATE_STATE_SHUTOFF:
        climate_current_state=CLIMATE_STATE_AIRCONDITIONING_ON;
        return;

    case CLIMATE_STATE_INIT:        
    }
}
void climate_event_lowTemperature(void){
    switch (climate_current_state)
    {
    case CLIMATE_STATE_RADIATOR_ON:
        
    case CLIMATE_STATE_AIRCONDITIONING_ON:
        
    case CLIMATE_STATE_SHUTOFF:
        climate_current_state=CLIMATE_STATE_RADIATOR_ON;
        return;

    case CLIMATE_STATE_INIT:
        
    }

}
void climate_event_turnOffTemperature(void){
    switch (climate_current_state)
    {
    case CLIMATE_STATE_RADIATOR_ON: /* range (22<t<25) */
        climate_current_state=CLIMATE_STATE_SHUTOFF;
        return;
    case CLIMATE_STATE_AIRCONDITIONING_ON: /* range (19<t<22) */
        climate_current_state=CLIMATE_STATE_SHUTOFF;
        return;
    case CLIMATE_STATE_SHUTOFF:

    case CLIMATE_STATE_INIT:        
        
    }

}





/*
#define LOWEST_TEMPERATURE 19
#define HIGHEST_TEMPERATURE 25
#define SHUTOFF_TEMPERATURE 22
*/



/*Temperature_Event temperature_check_event(int temperature){
    switch (temperature)
    {
        case LOWEST_TEMPERATURE:
            return LOW_TEMPERATURE;
            break;
        case HIGHEST_TEMPERATURE:
            return HIGH_TEMPERATURE;
            break;
        case SHUTOFF_TEMPERATURE:
            return TURNOFF_TEMPERATURE;
            break;
        default:
            break;
    }

}*/




