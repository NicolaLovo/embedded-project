#include "features/radiator/events.h"
#include "features/radiator/fsm.h"

#define LOWEST_TEMPERATURE 19
#define HIGHEST_TEMPERATURE 25
#define SHUTOFF_TEMPERATURE 22



Temperature_Event temperature_check_event(int temperature){
    switch (temperature)
    {
        case LOWEST_TEMPERATURE:
            return LOW_TEMPERATURE;
            break;
        case HIGHEST_TEMPERATURE:
            return HIGH_TEMPERATURE;
            break;
        case SHUTOFF_TEMPERATURE:
            return TURNOFF_TEMPERATURE;
            break;
        default:
            break;
    }

}



