#include "features/climate/events.h"
#include "features/climate/fsm.h"

//event that change state in "on radiator"
void climate_on_under_low(){
    climate_current_state=CLIMATE_STATE_RADIATOR;
}

//event that change state in "off"
void climate_on_above_idle(){
    climate_current_state=CLIMATE_STATE_OFF;
}

//event that change state in "on air conditioning"
void climate_on_above_high(){
    climate_current_state=CLIMATE_STATE_AIRCONDITIONING;
}

//event that change state in "off"
void climate_on_under_idle(){
    climate_current_state=CLIMATE_STATE_OFF;
}
