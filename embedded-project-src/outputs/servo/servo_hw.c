#include "servo_hw.h"

void servo_hw_init(void) {
    // Configure the servo signal pin as a primary function for Timer A0.2 (TA0.2)
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(SERVO_PORT, SERVO_PIN, GPIO_PRIMARY_MODULE_FUNCTION);

    // Timer A0 configuration in up mode
    Timer_A_PWMConfig pwmConfig = {
        TIMER_A_CLOCKSOURCE_SMCLK,     // Use SMCLK
        TIMER_A_CLOCKSOURCE_DIVIDER_1, // No divider
        TIMER_PERIOD,                  // 50 Hz period (20 ms)
        TIMER_A_CAPTURECOMPARE_REGISTER_2, // Use CCR2 (for TA0.2 on P2.5)
        TIMER_A_OUTPUTMODE_RESET_SET,  // Set/Reset mode for PWM
        SERVO_MIN_DUTY_CYCLE           // Initial pulse width: 0� position
    };

    // Generate PWM for Timer A0.2 on the abstracted port and pin
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig);
}


void rotate_servo_angle(uint8_t angle) {
    //bound servo angle between 0 and 180 to protect it
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;

    // Map 0-180 degrees to pwm pulse
    float dutyCycle = SERVO_MIN_DUTY_CYCLE + ((angle / 180.0f) * (SERVO_MAX_DUTY_CYCLE - SERVO_MIN_DUTY_CYCLE));

    // Update the PWM duty cycle
    MAP_Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2, (uint16_t)dutyCycle);
}
