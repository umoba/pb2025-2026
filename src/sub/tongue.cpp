#include "main.h"// IWYU pragma: keep
#include "globals.h"// IWYU pragma: keep
#include "subs_headers/tongue.h"
#include "pros/misc.h"
using namespace Robot;
using namespace Robot::Globals;

Tongue::Tongue() {}

void Tongue::run() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    tongue.toggle();
  }
}