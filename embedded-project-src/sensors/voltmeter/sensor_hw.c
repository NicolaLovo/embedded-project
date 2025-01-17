#include "sensor_hw.h"
#include "tools/HAL_I2C.h"
#include "tools/HAL_OPT3001.h"

void voltage_hw_init(void) {
  // Set voltage port as input with pull-up resistor
  GPIO_setAsInputPinWithPullUpResistor(ALLIGATOR_CLIP_PORT, ALLIGATOR_CLIP_PIN);
}

int voltage_is_high() {
  // Read voltage sensor value
  // int voltageReading = read_voltage();
  // return voltageReading >= VOLTAGE_THRESHOLD;
  int pinValue = GPIO_getInputPinValue(ALLIGATOR_CLIP_PORT, ALLIGATOR_CLIP_PIN);
  printf("Pin Value: %d\n", pinValue); // Print the pin value for debugging
  return pinValue == GPIO_INPUT_PIN_LOW;
}