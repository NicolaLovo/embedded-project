#include "outputs/rgbLED/rgbLED.h"

void rgb_led_hw_init(void) {
  // Set GPIO_PORT to output direction
  GPIO_setAsOutputPin(RGB_LED_PORT, RGB_LED_PIN);
  rgb_toggle_led(false);
}
void rgb_toggle_led(bool active) {
  if (active) {
    GPIO_setOutputHighOnPin(RGB_LED_PORT, RGB_LED_PIN); // Turn on LED
  } else {
    GPIO_setOutputLowOnPin(RGB_LED_PORT, RGB_LED_PIN); // Turn off LED
  }
}
