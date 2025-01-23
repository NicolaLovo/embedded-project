#include "outputs/rgbLED/rgbLED.h"

void rgb_led_hw_init(void) {
  GPIO_setAsOutputPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red LED 
  GPIO_setAsOutputPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green LED 
  GPIO_setAsOutputPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue LED 
    
  GPIO_setOutputLowOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn off 
}

void rgb_set_off() {
  GPIO_setOutputLowOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn off 
}

void rgb_set_red() {
  GPIO_setOutputHighOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn off 
}

void rgb_set_blue() {
  GPIO_setOutputLowOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputHighOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn off 
}
