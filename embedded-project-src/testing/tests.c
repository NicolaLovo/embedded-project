#include "config.h"

#ifdef TESTING

#include "testing/allarm/tests.h"
#include "testing/door/tests.h"
#include "testing/irrigation/tests.h"

void run_tests() {
  test_door_feature();
  test_allarm_feature();
  test_irrigation_feature();
}

#else

void run_tests() {
  // define as nothing
}

#endif
