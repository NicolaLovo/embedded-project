#include "sensor_hw.h"
#include "sensor_on_read.h" 
#include <stdint.h>



void climate_sensor_hw_init(void){
    /* Halting WDT */
    WDT_A_holdTimer();

    /* Configurazione dei LED */
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0); // LED Rosso
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1); // LED Verde
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2); // LED Blu
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0); // Spegni Rosso
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1); // Spegni Verde
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2); // Spegni Blu

    /* Setting reference voltage to 2.5 and enabling temperature sensor */
    REF_A_enableTempSensor();
    REF_A_setReferenceVoltage(REF_A_VREF2_5V);
    REF_A_enableReferenceVoltage();

    /* Lettura dei valori di calibrazione */
    cal30 = SysCtl_getTempCalibrationConstant(SYSCTL_2_5V_REF, SYSCTL_30_DEGREES_C);
    cal85 = SysCtl_getTempCalibrationConstant(SYSCTL_2_5V_REF, SYSCTL_85_DEGREES_C);
    calDifference = cal85 - cal30;

    /* Configurazione del modulo ADC */
    ADC14_enableModule();
    ADC14_initModule(ADC_CLOCKSOURCE_MCLK, ADC_PREDIVIDER_1, ADC_DIVIDER_1, ADC_TEMPSENSEMAP);

    /* Configurazione della memoria ADC per il sensore di temperatura */
    ADC14_configureSingleSampleMode(ADC_MEM0, true);
    ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_INTBUF_VREFNEG_VSS, ADC_INPUT_A22, false);

    /* Configurazione del tempo di campionamento */
    ADC14_setSampleHoldTime(ADC_PULSE_WIDTH_192, ADC_PULSE_WIDTH_192);

    /* Abilitazione del timer di campionamento in modalità iterativa automatica */
    ADC14_enableSampleTimer(ADC_AUTOMATIC_ITERATION);
    ADC14_enableInterrupt(ADC_INT0);

    /* Abilitazione delle interruzioni globali */
    Interrupt_enableInterrupt(INT_ADC14);
    Interrupt_enableMaster();

    /* Avvio della conversione */
    ADC14_enableConversion();
    ADC14_toggleConversionTrigger();

}

int climate_sensor_hw_readTemperature(void){

    int16_t conRes;
    float tempC;

    /* Attesa del completamento della conversione */
    while (!ADC14_isBusy()) {}

    /* Lettura del risultato dalla memoria ADC */
    conRes = ((ADC14_getResult(ADC_MEM0) - cal30) * 55);
    tempC = (conRes / calDifference) + 30.0f;

    return (int)tempC; // Restituisce la temperatura in gradi Celsius
    
}

//sensor interrupt handling 
void ADC14_IRQHandler(void){
    uint64_t status;
    int16_t conRes;

    status = ADC14_getEnabledInterruptStatus();
    ADC14_clearInterruptFlag(status);

    if (status & ADC_INT0)
    {
        conRes = ((ADC14_getResult(ADC_MEM0) - cal30) * 55);
        tempC = (conRes / calDifference) + 30.0f;

        /* Turn on/off led based on the temperature*/
        if (tempC < 19.0f)
        {
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0); // Accendi Rosso
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);  // Spegni Verde
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);  // Spegni Blu
        }
        else if (tempC >= 19.0f && tempC <= 22.0f)
        {
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);  // Spegni Rosso
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1); // Accendi Verde
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);  // Spegni Blu
        }
        else if (tempC > 22.0f && tempC <= 25.0f)
        {
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);  // Spegni Rosso
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1); // Accendi Verde
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);  // Spegni Blu
        }
        else if (tempC > 25.0f)
        {
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);  // Spegni Rosso
            GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);  // Spegni Verde
            GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2); // Accendi Blu
        }
    }
}






