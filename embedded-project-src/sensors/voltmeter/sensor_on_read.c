#include "sensor_on_read.h"
#include "sensor_hw.h"
#include "features/allarm/events.h"


void voltage_on_read(int voltage) {
    if(voltage_is_high()) {
        // high voltage
        allarm_event_onContact();
    } else {
        // low voltage
        allarm_event_onContactEnd();
    }
}