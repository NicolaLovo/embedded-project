#ifndef __IRRIGATION_BUTTON_ON_PRESS_H__
#define __IRRIGATION_BUTTON_ON_PRESS_H__

/**
 * Hw-independent function to be called by the door button isr
 * Calls accordingly the events to mutate the fsm of the features
 */
void irrigation_button_on_press(void);

#endif
