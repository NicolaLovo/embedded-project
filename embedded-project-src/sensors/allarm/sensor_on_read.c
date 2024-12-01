#include "sensor_on_read.h"

void buzzer_on_read(Contact contact)
{
    if (contact == TRUE)
    {
        /* Generate PWM to control the buzzer */
        Timer_A_outputPWM(TIMER_A0_BASE, &compareConfig_PWM);
    }
    else
    {
        /* Stop the buzzer */
        Timer_A_stopTimer(TIMER_A0_BASE);
    }
}