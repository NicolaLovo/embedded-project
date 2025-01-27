#include "outputs/blueLED/blueLED.h"

void blue_led_hw_init(void) {
  // Set GPIO_PORT to output direction
  GPIO_setAsOutputPin(BLUE_LED_PORT, BLUE_LED_PIN);
  blue_toggle_led(false);
}

// if active is true, turn on LED
void blue_toggle_led(bool active) {
  if (active) {
    GPIO_setOutputHighOnPin(BLUE_LED_PORT, BLUE_LED_PIN); // Turn on LED
  } else {
    GPIO_setOutputLowOnPin(BLUE_LED_PORT, BLUE_LED_PIN); // Turn off LED
  }
}
