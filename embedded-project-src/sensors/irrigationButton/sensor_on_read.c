#include "sensor_on_read.h"

#include "features/irrigation/fsm.h"
#include "features/irrigation/events.h"


void irrigation_button_on_press(void) {
    irrigation_event_button_pressed();
}
