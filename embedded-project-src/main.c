#include "msp.h"

#include "features/door/fsm.h"
#include "features/door/events.h"

#include "features/irrigation/fsm.h"
#include "features/irrigation/events.h"

#include "features/climate/events.h"
#include "features/climate/fsm.h"

#include "sensors/light/sensor_hw.h"


void hw_init(void) {
    // Initialize the light sensor
    light_hw_init();

}


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
        if(irrigation_current_state < IRRIGATION_NUM_STATES){
            (*irrigation_fsm[irrigation_current_state].state_function)();
        }
    }
    
    
    
    
}
