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
    
    
    
    
}
