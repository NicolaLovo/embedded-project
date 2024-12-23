#include <outputs/blueLED/blueLED.h>

#include "features/irrigation/fsm.h"
#include "features/irrigation/events.h"

volatile uint8_t cycleCount = 0;  // Counter to sum cycles

/* Timer_A UpMode Configuration Parameter */
const Timer_A_UpModeConfig upConfigA3 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_64,         // SMCLK/1 = 3MHz
        TIMER_PERIOD,                           // every half second
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR                        // Clear value
};

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

// Starting timer
void timerA3_start(void)
{
    // Configure Timer_A1 with given period
    Timer_A_configureUpMode(TIMER_A3_BASE, &upConfigA3);

    // Enable interrupt for Timer_A4
    Interrupt_enableInterrupt(INT_TA3_0);


    Timer_A_startCounter(TIMER_A3_BASE, TIMER_A_UP_MODE);  // Start timer
    Interrupt_enableMaster();  // Enable global interrupts
}

// Timer reset
void timerA3_reset(void)
{
    Timer_A_clearCaptureCompareInterrupt(TIMER_A3_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);  // Reset interrupt
    cycleCount = 0;  // Reset counter
}

void TA3_0_IRQHandler(void)
{
    cycleCount++;  // Increment counter

    if (cycleCount >= IRRIGATION_DURATION)  // Every ?? seconds
    {
        irrigation_event_timer_done();
        timerA3_reset();  // Reset timer and counter
    }

    // Reset interrupt for CCR0
    Timer_A_clearCaptureCompareInterrupt(TIMER_A3_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);
}
