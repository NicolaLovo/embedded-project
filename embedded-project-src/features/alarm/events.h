#ifndef __ALARM_EVENTS_H__
#define __ALARM_EVENTS_H__

/**
 * Called when light sensor detects darkness
 */

void alarm_event_skyDark(void);

/**
 * Called when  light sensor detects light
 */

void alarm_event_skyLight(void);

/**
 * Called when some contact is detected
 */

void alarm_event_onContact(void);

/**
 * Called when the contact is no longer detected
 */

void alarm_event_onContactEnd(void);


#endif 
