#include "sensor_on_read.h"

void light_on_read(float lux) {
    if(lux <= DARK_THRESHOLD) {

    } else if(lux >= BRIGHT_THRESHOLD) {

    } else {

    }
}
