#ifndef __ALLARM_EVENTS_H__
#define __ALLARM_EVENTS_H__

/**
 * Called when light sensor detects darkness
 */

void allarm_event_skyDark(void);

/**
 * Called when  light sensor detects light
 */

void allarm_event_skyLight(void);

/**
 * Called when some contact is detected
 */

void allarm_event_onContact(void);

/**
 * Called when the contact is no longer detected
 */

void allarm_event_onContactEnd(void);


#endif 