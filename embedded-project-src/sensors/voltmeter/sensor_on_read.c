#include "sensor_on_read.h"
#include "features/allarm/events.h"
#include "sensor_hw.h"

void voltage_on_read(int voltage, bool is_day) {
   if(is_day) {
       allarm_event_onContactEnd();
       return;
   }

  if (voltage_is_high()) {
    // high voltage
    allarm_event_onContact();
  } else {
    // low voltage
    allarm_event_onContactEnd();
  }
}
