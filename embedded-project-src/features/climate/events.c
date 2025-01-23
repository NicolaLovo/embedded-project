#include "features/climate/events.h"
#include "features/climate/fsm.h"

void climate_on_under_low(){
    if(climate_current_state==CLIMATE_STATE_OFF){
        climate_current_state=CLIMATE_STATE_RADIATOR;
    }

}
void climate_on_above_idle(){
    if(climate_current_state==CLIMATE_STATE_RADIATOR){
        climate_current_state=CLIMATE_STATE_OFF;
    }

}
void climate_on_above_high(){
    if(climate_current_state==CLIMATE_STATE_OFF){
        climate_current_state=CLIMATE_STATE_AIRCONDITIONING;
    }

}
void climate_on_under_idle(){
    if(climate_current_state==CLIMATE_STATE_AIRCONDITIONING){
        climate_current_state=CLIMATE_STATE_OFF;
    }
}