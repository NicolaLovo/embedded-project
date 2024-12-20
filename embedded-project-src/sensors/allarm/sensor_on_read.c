#include "sensor_on_read.h"
#include "features/allarm/events.h"

void buzzer_on_read(Contact contact)
{
    if (contact == TRUE)
    {
        allarm_event_onContact();
    }
    else
    {
        allarm_event_onContactEnd();
    }
}
