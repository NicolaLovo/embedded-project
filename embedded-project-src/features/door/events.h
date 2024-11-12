#ifndef __DOOR_EVENTS_H
#define __DOOR_EVENTS_H

/**
 * Called when light sensor detects darkness
 */
void door_event_skyDark(void);

/**
 * Called when the button for door open is clicked
 */
void door_event_button_open(void);

/**
 * Called when the button for door close is clicked
 */
void door_event_button_close(void);

/**
 * Called when the accelerometer detects an earthquake
 */
void door_event_earthquake_start(void);

/**
 * Called when the accelerometer detects the end of the earthquake
 */
void door_event_earthquake_end(void);



#endif
