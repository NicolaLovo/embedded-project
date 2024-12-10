#include "tools/HAL_I2C.h"
#include "tools/HAL_OPT3001.h"
#include "sensor_hw.h"

void light_hw_init(void) {
    /* Initialize I2C communication */
    Init_I2C_GPIO();
    I2C_init();

    /* Initialize OPT3001 digital ambient light sensor */
    OPT3001_init();
}

// todo: what is the light sensor isr routine?

float read_light(void) {
    float lux = OPT3001_getLux();
    return lux;
}
