#include "sensor_hw.h"
#include "tools/HAL_I2C.h"
#include "tools/HAL_OPT3001.h"

void voltage_hw_init(void) {
  // Set voltage port as input with pull-up resistor
  GPIO_setAsInputPinWithPullUpResistor(ALLIGATOR_CLIP_PORT, ALLIGATOR_CLIP_PIN);
}

int voltage_is_high() {

  return GPIO_getInputPinValue(ALLIGATOR_CLIP_PORT, ALLIGATOR_CLIP_PIN) ==
         GPIO_INPUT_PIN_LOW;
}