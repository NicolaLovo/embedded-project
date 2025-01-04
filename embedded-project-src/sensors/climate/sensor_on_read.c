#include "sensor_on_read.h"





/*switch (state){

    case OFF:
        if (tempC > HIGHEST_TEMPERATURE){
            fn_aria_condizionata();
        }
    case ON:
        if (tempC ...){

        }
        
}
*/
void climate_sensor_on_read_handleTemperature(void){
    int temperature= climate_sensor_hw_readTemperature();
    if (temperature<LOWEST_TEMPERATURE){
        climate_event_lowTemperature();

    }else if(temperature>HIGHEST_TEMPERATURE){
        climate_event_highTemperature();
    }else if(temperature< CLIMATE_SHUTOFF_TEMPERATURE || temperature> CLIMATE_SHUTOFF_TEMPERATURE){
        climate_event_turnOffTemperature();
    }
    

}
 


