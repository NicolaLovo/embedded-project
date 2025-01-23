#include "features/climate/events.h"
#include "features/climate/fsm.h"

void climate_on_under_low(){
    climate_current_state=CLIMATE_STATE_RADIATOR;

}
void climate_on_above_idle(){
    climate_current_state=CLIMATE_STATE_OFF;
}
void climate_on_above_high(){
    climate_current_state=CLIMATE_STATE_AIRCONDITIONING;
}
void climate_on_under_idle(){
    climate_current_state=CLIMATE_STATE_OFF;
}