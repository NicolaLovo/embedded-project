#ifndef __CLIMATE_EVENTS_H
#define __CLIMATE_EVENTS_H

#define CLIMATE_LOWEST_TEMPERATURE 19
#define CLIMATE_HIGHEST_TEMPERATURE 25
#define CLIMATE_SHUTOFF_TEMPERATURE 22


/**
No good: embedding constants in function names. Let's assign an alias to each event.
low = 19
high = 25
medium = 22
 
climate_on_under_medium() // temp < 22
climate_on_above_medium() // temp > 22

climate_on_under_low() // temp < 19
climate_on_above_high() // temp > 25

 */

void climate_event_under19(void);
void climate_event_above22(void);
void climate_event_above25(void);
void climate_event_under22(void);




#endif
