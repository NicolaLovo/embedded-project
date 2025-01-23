#ifndef __CLIMATE_EVENTS_H
#define __CLIMATE_EVENTS_H

#define CLIMATE_LOWEST_TEMPERATURE 19
#define CLIMATE_HIGHEST_TEMPERATURE 25
#define CLIMATE_IDLE_TEMPERATURE 22


/**
 * @brief Turn on the radiator if the temperature is below 19
 */
void climate_on_under_low(void);

/**
 * @brief Turn off the radiator if the temperature is above 22
 */
void climate_on_above_idle(void);

/**
 * @brief Turn on the air conditioning if the temperature is above 25
 */
void climate_on_under_idle(void);

/**
 * @brief Turn off the air conditioning if the temperature is above 25
 */
void climate_on_above_high(void);




#endif
