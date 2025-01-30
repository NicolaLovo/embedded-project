#include "outputs/rgbLED/rgbLED.h"

void rgb_led_hw_init(void) {
  //Set the pins of the three led (red, green and blue) as output
  GPIO_setAsOutputPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red LED 
  GPIO_setAsOutputPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green LED 
  GPIO_setAsOutputPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue LED 
  
  //Set all led initially off (low output)
  GPIO_setOutputLowOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn off 
}
//Set all led off
void rgb_set_off() { //Turns off all led by setting the output pins to LOW
  GPIO_setOutputLowOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn off 
}
//Set on only red led
void rgb_set_red() { //Only the red led (pin to HIGH).
  GPIO_setOutputHighOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn on 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn off 
}

//Set on only blue led
void rgb_set_blue() { //Only the blue led (pin to HIGH).
  GPIO_setOutputLowOnPin(RGB_LED_RED_PORT, RGB_LED_RED_PIN); // red:turn off 
  GPIO_setOutputLowOnPin(RGB_LED_GREEN_PORT, RGB_LED_GREEN_PIN); // green:turn off 
  GPIO_setOutputHighOnPin(RGB_LED_BLUE_PORT, RGB_LED_BLUE_PIN); // blue:turn on 
}
