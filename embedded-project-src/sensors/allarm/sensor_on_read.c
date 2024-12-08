#include "sensor_on_read.h"
#include "sensor_hw.h"

void buzzer_on_read(Contact contact)
{
    if (contact == TRUE)
    {
        buzzer_on();
    }
    else
    {
        buzzer_off();
    }
}
