#include "sensor_hw.h"
#include "driverlib/source/ti/devices/msp432p4xx/driverlib/driverlib.h"
#include "driverlib/source/ti/devices/msp432p4xx/inc/msp.h"

Timer_A_CompareModeConfig compareConfig_PWM = {
    TIMER_A_CAPTURECOMPARE_REGISTER_4,        // Use CCR3
    TIMER_A_CAPTURECOMPARE_INTERRUPT_DISABLE, // Disable CCR interrupt
    TIMER_A_OUTPUTMODE_TOGGLE_SET,            // Toggle output but
    10000                                     // 25% Duty Cycle initially
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
  GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);

  /* Configuring Timer_A0 for Up Mode and starting */
  Timer_A_configureUpMode(TIMER_A0_BASE, &upConfig);
  Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);

  /* Initialize compare registers to generate PWM */
  Timer_A_initCompare(TIMER_A0_BASE, &compareConfig_PWM); // For P2.7
}