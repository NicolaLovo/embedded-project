#ifndef __LIGHT_ON_READ_H__
#define __LIGHT_ON_READ_H__


#define DARK_THRESHOLD 100
#define BRIGHT_THRESHOLD 300

/**
 * Hw-independent function to be called by the door button isr
 * Calls accordingly the events to mutate the fsm of the features
 */
void door_button_on_press(void);

#endif
