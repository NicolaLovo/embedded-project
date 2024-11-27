#ifndef FEATURES_CLIMATE_EVENTS_H_
#define FEATURES_CLIMATE_EVENTS_H_

#define CLIMATE_LOWEST_TEMPERATURE 19
#define CLIMATE_HIGHEST_TEMPERATURE 25
#define CLIMATE_SHUTOFF_TEMPERATURE 22


void climate_event_highTemperature(void); //when sensor become hotter (t>25)
void climate_event_lowTemperature(void); //when sensor become colder  (t<19)
void climate_event_turnOffTemperature(void); //when sensor is in these range (22<t<25) ||(19<t<22)



/*typedef enum Temperature_Event{
    LOW_TEMPERATURE,
    TURNOFF_TEMPERATURE,
    HIGH_TEMPERATURE

}Temperature_Event;

Temperature_Event temperature_check_event(int temperature);*/




#endif