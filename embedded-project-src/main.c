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

#include "features/frontDoorLight/events.h"
#include "features/frontDoorLight/fsm.h"

#include "sensors/accelerometer/sensor_hw.h"
#include "sensors/accelerometer/sensor_on_read.h"
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
#include "outputs/servo/servo_hw.h"

#include "testing/tests.h"

#define IS_DAY "Is Sunny"
#define IS_NIGHT "Is Night"
#define ALARM_ON "Alarm  On"
#define ALARM_OFF "Alarm Off"
#define NO_EARTHQUAKE "                   "
#define EARTHQUAKE "!!! EARTHQUAKE !!!"


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
  int isEarthquake;

  while (1) {

    if (door_current_state < DOOR_NUM_STATES) {
      (*door_fsm[door_current_state].state_function)();
    }
    if (irrigation_current_state < IRRIGATION_NUM_STATES) {
      (*irrigation_fsm[irrigation_current_state].state_function)();
    }
    if (aLlarm_current_state < ALLARM_NUM_STATES) {
      (*aLlarm_fsm[aLlarm_current_state].state_function)();
    }
    if (front_door_current_state < FRONT_DOOR_LIGHT_NUM_STATES) {
      (*front_door_fsm[front_door_current_state].state_function)();
    }

    /**
     * Polling: not the best solution but for now we do not know how to use
     * interrupts
     */
    lux = read_light();
    light_on_read(lux);

    contact = voltage_is_high();
    isDay = light_is_day();
    voltage_on_read(contact, isDay);
    isEarthquake = earthquake_active();

    if (isDay == 1) {
      Graphics_drawStringCentered(&g_sContext, (int8_t *)IS_DAY,
                                  AUTO_STRING_LENGTH, 64, 40, OPAQUE_TEXT);
      Graphics_drawStringCentered(&g_sContext, (int8_t *)"              ",
                                  AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
    } else {
      Graphics_drawStringCentered(&g_sContext, (int8_t *)IS_NIGHT,
                                  AUTO_STRING_LENGTH, 64, 40, OPAQUE_TEXT);
      if (contact == 1) {
        Graphics_drawStringCentered(&g_sContext, (int8_t *)ALARM_ON,
                                    AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
      } else {
        Graphics_drawStringCentered(&g_sContext, (int8_t *)ALARM_OFF,
                                    AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
      }
    }

    if (isEarthquake) {
      Graphics_drawStringCentered(&g_sContext, (int8_t *)EARTHQUAKE,
                                  AUTO_STRING_LENGTH, 64, 70, OPAQUE_TEXT);
    } else {
      Graphics_drawStringCentered(&g_sContext, (int8_t *)NO_EARTHQUAKE,
                                  AUTO_STRING_LENGTH, 64, 70, OPAQUE_TEXT);
    }

    // Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext, (int8_t *)"Embedded Project:",
                                AUTO_STRING_LENGTH, 64, 20, OPAQUE_TEXT);
  }
}
