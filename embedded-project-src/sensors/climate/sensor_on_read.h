#ifndef __SENSOR_ON_READ_H__
#define __SENSOR_ON_READ_H__

#include "sensor_hw.h"
#include "features/climate/events.h"
#include "features/climate/fsm.h"

#define LOWEST_TEMPERATURE 19
#define HIGHEST_TEMPERATURE 25
#define SHUTOFF_TEMPERATURE 22

//combine event and temperature 
void climate_sensor_on_read_handleTemperature(void);






#endif