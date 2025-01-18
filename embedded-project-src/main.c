#include "msp.h"
#include "config.h"

#include "features/door/events.h"
#include "features/door/fsm.h"

#include "features/irrigation/events.h"
#include "features/irrigation/fsm.h"

#include "features/climate/events.h"
#include "features/climate/fsm.h"

#include "features/allarm/events.h"
#include "features/allarm/fsm.h"

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

#include "outputs/buzzer/buzzer_hw.h"
#include "outputs/servo/servo_hw.h"

#include "testing/tests.h"

#include "tools/LcdDriver/Crystalfontz128x128_ST7735.h"
#include "tools/LcdDriver/HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"
#include <stdio.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/grlib/grlib.h>

Graphics_Context g_sContext;

#define IS_DAY "Is Sunny"
#define IS_NIGHT "Is Night"
#define ALLARM_ON "Allarm  On"
#define ALLARM_OFF "Allarm Off"

void graphicsInit() {
  /* Initializes display */
  Crystalfontz128x128_Init();

  /* Set default screen orientation */
  Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

  /* Initializes graphics context */
  Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128,
                       &g_sCrystalfontz128x128_funcs);
  Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
  Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
  GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
  Graphics_clearDisplay(&g_sContext);
  Graphics_drawStringCentered(&g_sContext,
                              (int8_t *)"Embedded Project:", AUTO_STRING_LENGTH,
                              64, 30, OPAQUE_TEXT);
}

void hw_init(void) {
  // Initialize the light sensor
  light_hw_init();

  // Initialize the buzzer
  buzzer_hw_init();

  // Initialize door button
  door_button_hw_init();

  // Initialize irrigation button
  irrigation_button_hw_init();

  // Initialize accelerometer
  accelerometer_hw_init();

  servo_hw_init();

  voltage_hw_init();

  graphicsInit();
}

float lux;

/**
 * main.c
 */
void main(void) {
#ifdef TESTING

  run_tests();

#endif


  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // stop watchdog timer

  hw_init();

  //  while (1) {
  //     // Move to 0� position
  //     rotate_servo_angle(0);
  //     __delay_cycles(3000000); // 3-second delay

  //     // Move to 90� position
  //     rotate_servo_angle(90);
  //     __delay_cycles(3000000); // 3-second delay

  //     // Move to 180� position
  //     rotate_servo_angle(180);
  //     __delay_cycles(3000000); // 3-second delay
  // }

  float lux;
  int contact;
  int isDay;

  while (1) {

    if (door_current_state < DOOR_NUM_STATES) {
      (*door_fsm[door_current_state].state_function)();
    }
    if (irrigation_current_state < IRRIGATION_NUM_STATES) {
      (*irrigation_fsm[irrigation_current_state].state_function)();
    }
    if (allarm_current_state < ALLARM_NUM_STATES) {
      (*allarm_fsm[allarm_current_state].state_function)();
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

    // buzzer_on(); //Worka

    contact = voltage_is_high();
    isDay = light_is_day();

    if (isDay == 1) {
      buzzer_off();
      Graphics_drawStringCentered(&g_sContext, (int8_t *)IS_DAY,
                                  AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
    } else {
      Graphics_drawStringCentered(&g_sContext, (int8_t *)IS_NIGHT,
                                  AUTO_STRING_LENGTH, 64, 50, OPAQUE_TEXT);
      if (contact == 1) {
        buzzer_on();
        Graphics_drawStringCentered(&g_sContext, (int8_t *)ALLARM_ON,
                                    AUTO_STRING_LENGTH, 64, 60, OPAQUE_TEXT);
      } else {
        buzzer_off();
        Graphics_drawStringCentered(&g_sContext, (int8_t *)ALLARM_OFF,
                                    AUTO_STRING_LENGTH, 64, 60, OPAQUE_TEXT);
      }
    }

    // Graphics_clearDisplay(&g_sContext);
    Graphics_drawStringCentered(&g_sContext, (int8_t *)"Embedded Project:",
                                AUTO_STRING_LENGTH, 64, 30, OPAQUE_TEXT);

    // buzzer_off(); //Worka in qualche maniera, ma non credo sia corretto come
    // l'ho fatto haha

    // rotate_servo_angle(0);    // Rotate to 0�

    // rotate_servo_angle(90);   // Rotate to 90�

    // rotate_servo_angle(180);  // Rotate to 180�
  }
}
