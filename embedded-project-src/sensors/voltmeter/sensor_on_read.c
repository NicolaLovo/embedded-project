#include "sensor_on_read.h"
#include "features/allarm/events.h"
#include "sensor_hw.h"

void voltage_on_read(int voltage, bool is_day) {
  if (is_day) {
    allarm_event_skyLight();
  } else {
    allarm_event_skyDark();
  }

  if (voltage_is_high() && !is_day) {
    allarm_event_onContact();
  } else {
    allarm_event_onContactEnd();
  }
}
