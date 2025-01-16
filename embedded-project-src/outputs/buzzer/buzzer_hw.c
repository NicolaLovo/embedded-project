#include "buzzer_hw.h"

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/devices/msp432p4xx/inc/msp.h>

Timer_A_CompareModeConfig compareConfig_PWM = {
    TIMER_A_CAPTURECOMPARE_REGISTER_4,        // Use CCR3
    TIMER_A_CAPTURECOMPARE_INTERRUPT_DISABLE, // Disable CCR interrupt
    TIMER_A_OUTPUTMODE_TOGGLE_SET,            // Toggle output but
    10000                                     // 25% Duty Cycle initially
};

Timer_A_CompareModeConfig compareConfig_PWM2 = {
    TIMER_A_CAPTURECOMPARE_REGISTER_4,        // Use CCR3
    TIMER_A_CAPTURECOMPARE_INTERRUPT_DISABLE, // Disable CCR interrupt
    TIMER_A_OUTPUTMODE_TOGGLE_SET,            // Toggle output but
    0                                         // 25% Duty Cycle initially
};

/* Timer_A Up Configuration Parameter */
const Timer_A_UpModeConfig upConfig = {
    TIMER_A_CLOCKSOURCE_SMCLK,           // SMCLK = 3 MhZ
    TIMER_A_CLOCKSOURCE_DIVIDER_12,      // SMCLK/12 = 250 KhZ
    20000,                               // 40 ms tick period
    TIMER_A_TAIE_INTERRUPT_DISABLE,      // Disable Timer interrupt
    TIMER_A_CCIE_CCR0_INTERRUPT_DISABLE, // Disable CCR0 interrupt
    TIMER_A_DO_CLEAR                     // Clear value
};

void buzzer_hw_init(void)
{
  /* Configures P2.7 to PM_TA0.4 for using Timer PWM to control the buzzer */
  /**
   * The port J4.40 on BoosterPack MKII is connected to the P2.7 on the MSP432P401R
   */
  GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

  /* Configuring Timer_A0 for Up Mode and starting */
  Timer_A_configureUpMode(TIMER_A3_BASE, &upConfig);
  // Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);

  /* Initialize compare registers to generate PWM */
  // Timer_A_initCompare(TIMER_A0_BASE, &compareConfig_PWM); // For P2.7
}

void buzzer_on(void)
{
  Timer_A_startCounter(TIMER_A3_BASE, TIMER_A_UP_MODE);
  // Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_4, 20000); // 100% Duty Cycle waht is this?
  Timer_A_initCompare(TIMER_A3_BASE, &compareConfig_PWM);
}

void buzzer_off(void)
{
  // Timer_A_stopCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
  Timer_A_initCompare(TIMER_A3_BASE, &compareConfig_PWM2);
}
