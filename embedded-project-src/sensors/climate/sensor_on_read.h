#ifndef __SENSOR_ON_READ_H__
#define __SENSOR_ON_READ_H__

#include "sensor_hw.h"
#include "features/climate/events.h"
#include "features/climate/fsm.h"

//reference constants
#define LOWEST_TEMPERATURE 19
#define HIGHEST_TEMPERATURE 25
#define IDLE_TEMPERATURE 22

//Capture the current temperature and trigger the corresponding event
void climate_sensor_on_read(float temperature);



#endif
