#ifndef __VOLTMETER_ON_READ_H__
#define __VOLTMETER_ON_READ_H__

#include <stdbool.h>

/**
 * Hw-independent function to be called by the voltage is
 * Calls accordingly the events to mutate the fsm of the features
 */

void voltage_on_read(int voltage, bool is_day);

#endif
