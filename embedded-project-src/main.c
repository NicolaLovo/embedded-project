#include "msp.h"

#include "features/door/fsm.h"
#include "features/door/events.h"

#include "features/radiator/events.h"
#include "features/radiator/fsm.h"


/**
 * main.c
 */
void main(void)
{

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    while(1){
        if(door_current_state < DOOR_NUM_STATES){
            (*door_fsm[door_current_state].state_function)();
        }
    }
    
    //climate system 
    int temperature;
    Temperature_State fn_climateSystem_init(); //init off
    Temperature_State temperature_current_state;

    Temperature_Event temperature_event= temperature_check_event(temperature); 
    temperature_current_state= new_temperature_current_state(temperature_current_state, temperature_event);
    
    
    
}
