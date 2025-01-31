#include <stdio.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/grlib/grlib.h>

#include "config.h"
#include "msp.h"

#include "lcdDisplay/lcdInit.h"

#include "features/door/events.h"
#include "features/door/fsm.h"

#include "features/irrigation/events.h"
#include "features/irrigation/fsm.h"

#include "features/climate/events.h"
#include "features/climate/fsm.h"

#include "features/alarm/events.h"
#include "features/alarm/fsm.h"

#include "sensors/accelerometer/sensor_hw.h"
#include "sensors/accelerometer/sensor_on_read.h"
#include "sensors/climate/sensor_hw.h"
#include "sensors/climate/sensor_on_read.h"
#include "sensors/doorButton/sensor_hw.h"
#include "sensors/irrigationButton/sensor_hw.h"
#include "sensors/irrigationButton/sensor_on_read.h"
#include "sensors/light/sensor_hw.h"
#include "sensors/light/sensor_on_read.h"
#include "sensors/voltmeter/sensor_hw.h"
#include "sensors/voltmeter/sensor_on_read.h"

#include "outputs/blueLED/blueLED.h"
#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/redLED/redLED.h"
#include "outputs/rgbLED/rgbLED.h"
#include "outputs/servo/servo_hw.h"

#include "testing/tests.h"

#define SCREEN_IS_DAY_STRING "Is Sunny"
#define SCREEN_IS_NIGHT_STRING "Is Night"
#define SCREEN_ALARM_ON_STRING "Alarm  On"
#define SCREEN_ALARM_OFF_STRING "Alarm Off"
#define SCREEN_ALARM_IDLE_STRING "              "
#define SCREEN_NO_EARTHQUAKE_STRING "                   "
#define SCREEN_EARTHQUAKE_STRING "!!! EARTHQUAKE !!!"
#define SCREEN_IS_WARM_STRING "Air conditioning on"
#define SCREEN_IS_COLD_STRING "Radiator on"
#define SCREEN_DOOR_OPEN_STRING "Door opened"
#define SCREEN_DOOR_CLOSE_STRING "Door closed"

/**
 * Initialize all the hardware components
 */
void hw_init(void) {
  light_hw_init();

  buzzer_hw_init();

  door_button_hw_init();

  irrigation_button_hw_init();

  accelerometer_hw_init();

  servo_hw_init();

  voltage_hw_init();

  lcd_hw_init();

  blue_led_hw_init();

  red_led_hw_init();

  climate_sensor_hw_init();

  rgb_led_hw_init();
}

void main(void) {
#ifdef TESTING

  run_tests();

#endif
  // stop watchdog timer
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

  hw_init();

  float lux;
  int contact;
  int isDay;
  int isEarthquake = 0;
  float temperature = IDLE_TEMPERATURE;
  while (1) {

    if (door_current_state < DOOR_NUM_STATES) {
      (*door_fsm[door_current_state].state_function)();
    }
    if (irrigation_current_state < IRRIGATION_NUM_STATES) {
      (*irrigation_fsm[irrigation_current_state].state_function)();
    }
    if (alarm_current_state < ALARM_NUM_STATES) {
      (*alarm_fsm[alarm_current_state].state_function)();
    }
    if (climate_current_state < CLIMATE_NUM_STATES) {
      (*climate_fsm[climate_current_state].state_function)();
    }


    lux = read_light();
    temperature = climate_sensor_hw_readTemperature();
    light_on_read(lux);
    climate_sensor_on_read(temperature);

    // Cristiano part, apart from the light_is_day() function

    // Check if the voltage is high or low
    contact = voltage_is_high();
    // Check if is day or night
    isDay = light_is_day();
    // set the alarm state machine. If is day alarm is in the idle state, if is
    // night alarm is active and when a contact is detected the buzzer and the
    // red led are turned on
    voltage_on_read(contact, isDay);

    isEarthquake = earthquake_active();

    if (isDay == 1) {
      Graphics_drawStringCentered(&g_sContext, (int8_t *)SCREEN_IS_DAY_STRING,
                                  AUTO_STRING_LENGTH, 64, 40, OPAQUE_TEXT);
      Graphics_drawStringCentered(&g_sContext,
                                  (int8_t *)SCREEN_ALARM_IDLE_STRING,
                                  AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
    } else {
      Graphics_drawStringCentered(&g_sContext, (int8_t *)SCREEN_IS_NIGHT_STRING,
                                  AUTO_STRING_LENGTH, 64, 40, OPAQUE_TEXT);
      if (contact == 1) {
        Graphics_drawStringCentered(&g_sContext,
                                    (int8_t *)SCREEN_ALARM_ON_STRING,
                                    AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
      } else {
        Graphics_drawStringCentered(&g_sContext,
                                    (int8_t *)SCREEN_ALARM_OFF_STRING,
                                    AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
      }
    }

    if (isEarthquake) {
      Graphics_drawStringCentered(&g_sContext,
                                  (int8_t *)SCREEN_EARTHQUAKE_STRING,
                                  AUTO_STRING_LENGTH, 64, 70, OPAQUE_TEXT);
    } else {
      Graphics_drawStringCentered(&g_sContext,
                                  (int8_t *)SCREEN_NO_EARTHQUAKE_STRING,
                                  AUTO_STRING_LENGTH, 64, 70, OPAQUE_TEXT);
    }
    char tempString[10];
    sprintf(tempString, "Temp: %.2f", temperature);
    Graphics_drawStringCentered(&g_sContext, (int8_t *)tempString,
                                AUTO_STRING_LENGTH, 64, 80, OPAQUE_TEXT);

    switch (door_current_state) {
    case DOOR_STATE_OPEN:
    case DOOR_STATE_FORCE_OPEN:
      Graphics_drawStringCentered(&g_sContext,
                                  (int8_t *)SCREEN_DOOR_OPEN_STRING,
                                  AUTO_STRING_LENGTH, 64, 110, OPAQUE_TEXT);
      break;
    case DOOR_STATE_CLOSE:
      Graphics_drawStringCentered(&g_sContext,
                                  (int8_t *)SCREEN_DOOR_CLOSE_STRING,
                                  AUTO_STRING_LENGTH, 64, 110, OPAQUE_TEXT);
      break;
    }

    // Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext, (int8_t *)"Embedded Project:",
                                AUTO_STRING_LENGTH, 64, 20, OPAQUE_TEXT);
  }
}
