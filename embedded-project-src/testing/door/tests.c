#include "config.h"
#include "testing/tools.h"
#include "features/door/fsm.h"
#include "features/door/events.h"

#ifdef TESTING

/**
 * Run the current door fsm function
 */
void run_door_fsm() {
    if(door_current_state < DOOR_NUM_STATES){
        (*door_fsm[door_current_state].state_function)();
    }
}

void test_door_feature() {
    /**
     * verify door is initialized
     */
    assert(door_current_state == DOOR_STATE_INIT);
    run_door_fsm();

    /**
     * verify door is open after being initialized
     */
    assert(door_current_state == DOOR_STATE_OPEN);
    run_door_fsm();


    /**
     * trigger event: sky dark -> expect door closed
     */
    door_event_skyDark();
    assert(door_current_state == DOOR_STATE_CLOSE);
    run_door_fsm();

    /**
     * trigger event: button open -> expect door open
     */
    door_event_button_force_open();
    assert(door_current_state == DOOR_STATE_FORCE_OPEN);
    run_door_fsm();

    /**
     * trigger event: button close -> expect door closed
     */
    door_event_button_close();
    assert(door_current_state == DOOR_STATE_CLOSE);
    run_door_fsm();


    /**
     * trigger event: earthquake -> expect door force open
     */
    door_event_earthquake_start();
    assert(door_current_state == DOOR_STATE_FORCE_OPEN);
    run_door_fsm();

    /**
     * trigger event: earthquake end -> expect door open
     */
    door_event_earthquake_end();
    assert(door_current_state == DOOR_STATE_OPEN);
    run_door_fsm();


}

#else

#endif
