#ifndef __IRRIGATION_EVENTS_H
#define __IRRIGATION_EVENTS_H

#define LOW_TEMP 20
#define HIGH_TEMP 30

// Called when temp sensor is high (above 30)
void irrigation_event_highTemp(void);

// Called when temp sensor is low (under 20)
void irrigation_event_lowTemp(void);

// Called when the timer reaches a specified number
void irrigation_event_timer_done(void);

//  Called when the button for irrigation activation is pressed
void irrigation_event_button_on(void);

// Called when the button for irrigation ending is pressed
void irrigation_event_button_off(void);

#endif
