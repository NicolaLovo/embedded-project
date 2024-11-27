#ifndef __IRRIGATION_EVENTS_H
#define __IRRIGATION_EVENTS_H

// Called when temp sensor is high (above a threshold)
void irrigation_event_highTemp(void);

// Called when temp sensor is low (under a threshold)
void irrigation_event_lowTemp(void);

// Called when the irrigation is on
void irrigation_event_timer_count(void);

// Called when the timer reaches a specified number
void irrigation_event_timer_done(void);

//  Called when the button for irrigation activation is pressed
void irrigation_event_button_on(void);

// Called when the button for irrigation ending is pressed
void irrigation_event_button_off(void);

#endif
