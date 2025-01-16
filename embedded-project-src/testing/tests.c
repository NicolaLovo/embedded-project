#include "config.h"


#ifdef TESTING

#include "testing/door/tests.h"

void run_tests() {
    test_door_feature();
}

#else


void run_tests() {
    // define as nothing

}

#endif
