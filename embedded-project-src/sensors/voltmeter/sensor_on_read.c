#include "sensor_on_read.h"
#include "features/alarm/events.h"
#include "sensor_hw.h"

// Function called to set the alarm state, active if is night, and buzzer active
// if a contact is detected
void voltage_on_read(int voltage, bool is_day) {
  if (is_day) {
    alarm_event_skyLight();
  } else {
    alarm_event_skyDark();
  }

  if (voltage_is_high() && !is_day) {
    alarm_event_onContact();
  } else {
    alarm_event_onContactEnd();
  }
}
