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
#include "sensors/light/sensor_on_read.h"
#include "sensors/doorButton/sensor_hw.h"
#include "sensors/accelerometer/sensor_hw.h"
#include "sensors/accelerometer/sensor_on_read.h"

#include "outputs/servo/servo_hw.h"
#include "outputs/buzzer/buzzer_hw.h"


void hw_init(void) {
    // Initialize the light sensor
    light_hw_init();

    // Initialize the buzzer
    buzzer_hw_init();

    // Initialize door button
    door_button_hw_init();

    // Initialize accelerometer
    accelerometer_hw_init();

    servo_hw_init();

}

float lux;

/**
 * main.c
 */
void main(void)
{

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	hw_init();


	//  while (1) {
    //     // Move to 0� position
    //     rotate_servo_angle(0);
    //     __delay_cycles(3000000); // 3-second delay

    //     // Move to 90� position
    //     rotate_servo_angle(90);
    //     __delay_cycles(3000000); // 3-second delay

    //     // Move to 180� position
    //     rotate_servo_angle(180);
    //     __delay_cycles(3000000); // 3-second delay
    // }

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

        /**
         * Polling: not the best solution but for now we do not know how to use interrupts
         */
        lux = read_light();
        light_on_read(lux);


        buzzer_on(); //Worka

        //buzzer_off(); //Worka in qualche maniera, ma non credo sia corretto come l'ho fatto haha

        //rotate_servo_angle(0);    // Rotate to 0�

          //rotate_servo_angle(90);   // Rotate to 90�

          //rotate_servo_angle(180);  // Rotate to 180�


    }
    
    
    
    
}
