#include "sensor_on_read.h"
#include "sensor_hw.h"
#include "features/door/events.h"


void light_on_read(float lux) {
    if(lux <= DAY_THRESHOLD) {
        // day
        door_event_skyDark();
    } else {
        // night
    }
}


