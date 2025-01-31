#include "outputs/redLED/redLED.h"

// Initialize red led
void red_led_hw_init(void) {
  // Set GPIO_PORT to output direction
  GPIO_setAsOutputPin(RED_LED_PORT, RED_LED_PIN);
  // Turn off red led
  red_toggle_led(false);
}
void red_toggle_led(bool active) {
  if (active) {
    // Turn on LED
    GPIO_setOutputHighOnPin(RED_LED_PORT, RED_LED_PIN);
  } else {
    // Turn off LED
    GPIO_setOutputLowOnPin(RED_LED_PORT, RED_LED_PIN);
  }
}
