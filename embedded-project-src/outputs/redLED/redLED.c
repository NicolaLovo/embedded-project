#include "outputs/redLED/redLED.h"

void red_led_hw_init(void) {
    // Set GPIO_PORT to output direction
    GPIO_setAsOutputPin(RED_LED_PORT,RED_LED_PIN);
}
void red_toggle_led(bool active){
        if (active){
            printf("led on\n");
            GPIO_setOutputHighOnPin(RED_LED_PORT, RED_LED_PIN); // Turn on LED
        }
        else {
            printf("led off\n");
            GPIO_setOutputLowOnPin(RED_LED_PORT, RED_LED_PIN); // Turn off LED
        }

}

