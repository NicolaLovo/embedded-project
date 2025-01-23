#include "sensor_on_read.h"
#include "sensor_hw.h"
#include "features/climate/events.h"



void climate_sensor_on_read(float temperature){
    if (temperature < LOWEST_TEMPERATURE) {
        climate_on_under_low();
    } else if (temperature >= LOWEST_TEMPERATURE && temperature < IDLE_TEMPERATURE) {
        climate_on_above_idle();
    } else if (temperature >= IDLE_TEMPERATURE && temperature < HIGHEST_TEMPERATURE) {
        climate_on_under_idle();
    } else if (temperature >= HIGHEST_TEMPERATURE) {
        climate_on_above_high();
    }
}
 


