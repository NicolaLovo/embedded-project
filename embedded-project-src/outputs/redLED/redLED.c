#include "outputs/redLED/redLED.h"

void red_led_hw_init(void) {
  // Set GPIO_PORT to output direction
  GPIO_setAsOutputPin(RED_LED_PORT, RED_LED_PIN);
  red_toggle_led(false);
}
void red_toggle_led(bool active) {
  if (active) {
    GPIO_setOutputHighOnPin(RED_LED_PORT, RED_LED_PIN); // Turn on LED
  } else {
    GPIO_setOutputLowOnPin(RED_LED_PORT, RED_LED_PIN); // Turn off LED
  }
}
