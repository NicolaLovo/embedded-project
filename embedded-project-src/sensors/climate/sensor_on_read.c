#include "sensor_on_read.h"
#include "sensor_hw.h"
#include "features/events.h"



void climate_sensor_on_read(void){
    int temperature= climate_sensor_hw_readTemperature();
    if (temperature < LOWEST_TEMPERATURE) {
        climate_event_under19();
    } else if (temperature >= LOWEST_TEMPERATURE && temperature < SHUTOFF_TEMPERATURE) {
        climate_event_above22();
    } else if (temperature >= SHUTOFF_TEMPERATURE && temperature < HIGHEST_TEMPERATURE) {
        climate_event_under22();
    } else if (temperature >= HIGHEST_TEMPERATURE) {
        climate_event_above25();
    }
}
 


