#include "config.h"

#ifdef TESTING

#include "testing/alarm/tests.h"
#include "testing/door/tests.h"
#include "testing/climate/tests.h"
#include "testing/irrigation/tests.h"

void run_tests() {
  test_door_feature();
  test_alarm_feature();
  test_irrigation_feature();
  test_climate_feature();
}

#else

void run_tests() {
  // define as nothing
}

#endif
