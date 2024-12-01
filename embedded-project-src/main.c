#include "msp.h"

#include "features/door/fsm.h"
#include "features/door/events.h"

#include "features/irrigation/fsm.h"
#include "features/irrigation/events.h"

#include "features/climate/events.h"
#include "features/climate/fsm.h"

#include "features/allarm/events.h"
#include "features/allarm/fsm.h"

#include "features/frontDoorLight/events.h"
#include "features/frontDoorLight/fsm.h"

#include "sensors/light/sensor_hw.h"
#include "sensors/allarm/sensor_hw.h"


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
        if(allarm_current_state < ALLARM_NUM_STATES){
            (*allarm_fsm[allarm_current_state].state_function)();
        }
        if(front_door_current_state < FRONT_DOOR_LIGHT_NUM_STATES){
            (*front_door_fsm[front_door_current_state].state_function)();
        }

    }
    
    
    
    
}
