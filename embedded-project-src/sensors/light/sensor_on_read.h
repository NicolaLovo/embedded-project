#ifndef __LIGHT_ON_READ_H__
#define __LIGHT_ON_READ_H__


#define DARK_THRESHOLD 1000
#define BRIGHT_THRESHOLD 2000

/**
 * Hw-independent function to be called by the light isr
 * Calls accordingly the events to mutate the fsm of the features
 */
void light_on_read(float lux);

#endif
