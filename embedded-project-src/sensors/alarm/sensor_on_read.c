#include "sensor_on_read.h"
#include "features/alarm/events.h"

// Function called when the contact sensor detects contact (is night) and
// toggles the alarm
void buzzer_on_read(Contact contact) {
  if (contact == TRUE) {
    alarm_event_onContact();
  } else {
    alarm_event_onContactEnd();
  }
}
