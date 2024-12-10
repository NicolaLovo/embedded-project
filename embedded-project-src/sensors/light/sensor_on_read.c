#include "sensor_on_read.h"
#include "features/door/events.h"


void light_on_read(float lux) {
    if(lux <= DARK_THRESHOLD) {
        door_event_skyDark();
    } else if(lux >= BRIGHT_THRESHOLD) {

    } else {

    }
}
