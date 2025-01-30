#include "sensor_hw.h"
#include "tools/HAL_I2C.h"
#include "tools/HAL_OPT3001.h"

// Initialize the hardware for the voltage sensor
void voltage_hw_init(void) {
  // Set voltage port as input with pull-up resistor
  GPIO_setAsInputPinWithPullUpResistor(ALLIGATOR_CLIP_PORT, ALLIGATOR_CLIP_PIN);
}

// Boolean function to check if the voltage is high (1) or low (0)
int voltage_is_high() {

  return GPIO_getInputPinValue(ALLIGATOR_CLIP_PORT, ALLIGATOR_CLIP_PIN) ==
         GPIO_INPUT_PIN_LOW;
}
