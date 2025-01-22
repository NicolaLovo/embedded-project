#include "features/climate/events.h"
#include "features/climate/fsm.h"

void climate_event_under19(){
    if(climate_current_state==CLIMATE_STATE_OFF){
        climate_current_state=CLIMATE_STATE_RADIATOR;
    }

}
void climate_event_above22(){
    if(climate_current_state==CLIMATE_STATE_RADIATOR){
        climate_current_state=CLIMATE_STATE_OFF;
    }

}
void climate_event_above25(){
    if(climate_current_state==CLIMATE_STATE_OFF){
        climate_current_state=CLIMATE_STATE_AIRCONDITIONING;
    }

}
void climate_event_under22(){
    if(climate_current_state==CLIMATE_STATE_AIRCONDITIONING){
        climate_current_state=CLIMATE_STATE_OFF;
    }
}