#include "servo_hw.h"

void servo_hw_init(void) {

    // Configure port as a primary module function for PWM output (TA1.1)
    // TA0 is used for buzzer
    GPIO_setAsPeripheralModuleFunctionOutputPin(SERVO_PORT, SERVO_PIN, GPIO_PRIMARY_MODULE_FUNCTION);

    // Configure Timer_A1 for PWM mode
    Timer_A_PWMConfig pwmConfig = {
       TIMER_A_CLOCKSOURCE_SMCLK,        // Use the SMCLK clock source (3 MHz default)
       TIMER_A_CLOCKSOURCE_DIVIDER_64,   // Divide the clock by 64 (3MHz / 64 = 46.875 kHz)
       37500,                            // Period (20 ms for 50 Hz) (46.875 kHz / 50 Hz = 937.5)
       TIMER_A_CAPTURECOMPARE_REGISTER_1, // Use TA1.1 (linked to P2.4)
       TIMER_A_OUTPUTMODE_RESET_SET,      // Reset/set output mode
       0                                  // Duty cycle (this will be set later)
    };

    // Initialize the PWM for Timer_A1
    Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfig);
}


void rotate_servo_angle(uint8_t angle) {
    if (angle > 180) angle = 180; // Clamp angle to 180 degrees

    // Calculate the duty cycle corresponding to the angle
    // 1ms = 5% duty (for 0 degrees), 2ms = 10% duty (for 180 degrees)
    // Duty cycle = (angle / 180.0) * (10% - 5%) + 5%
    float dutyCyclePercent = (angle / 180.0f) * 5.0f + 5.0f; // Duty cycle (as percentage)
    uint16_t dutyCycleCounts = (uint16_t)((dutyCyclePercent / 100.0f) * 37500); // Convert to timer counts

    // Update the PWM duty cycle
    Timer_A_setCompareValue(TIMER_A1_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1, dutyCycleCounts);

}
