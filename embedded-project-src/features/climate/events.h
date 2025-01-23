#ifndef __CLIMATE_EVENTS_H
#define __CLIMATE_EVENTS_H

#define CLIMATE_LOWEST_TEMPERATURE 19
#define CLIMATE_HIGHEST_TEMPERATURE 25
#define CLIMATE_SHUTOFF_TEMPERATURE 22



void climate_event_under19(void);
void climate_event_above22(void);
void climate_event_above25(void);
void climate_event_under22(void);




#endif
