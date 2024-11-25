#ifndef FEATURES_RADIATOR_EVENTS_H_
#define FEATURES_RADIATOR_EVENTS_H_


typedef enum Temperature_Event{
    LOW_TEMPERATURE,
    TURNOFF_TEMPERATURE,
    HIGH_TEMPERATURE

}Temperature_Event;

Temperature_Event temperature_check_event(int temperature);



#endif