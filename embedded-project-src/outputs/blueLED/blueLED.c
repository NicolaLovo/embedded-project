#include <outputs/blueLED/blueLED.h>

void led_hw_init(void) {
    // Set GPIO_PORT to output direction
    GPIO_setAsOutputPin(LED_PORT,LED_PIN);
}
void toggle_led(bool active){
        if (active){
            GPIO_setOutputHighOnPin(LED_PORT, LED_PIN); // Turn on LED
        }
        else {
            GPIO_setOutputLowOnPin(LED_PORT, LED_PIN); // Turn off LED
        }

}

