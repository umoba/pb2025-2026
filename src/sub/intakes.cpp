// #include "main.h"
#include "subs_headers/intakes.h"

#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"

using namespace Robot;
using namespace Robot::Globals;


Intake::Intake() : running(false), runningrev(false), stopped(false), state(0) {}

bool red = false;
static bool elevate;
static int states[4] = {1, 2, 3, 4};
// Run the intake
void Intake::run() {
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
      intakes.move_velocity(600);
      running = !running; 
      runningrev = false;
  }
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
      intakes.move_velocity(-600);
      runningrev = !runningrev; 
      running = false;
  }
}

// Toggle whether the intake is stopping the blocks from scoring or not
void Intake::toggleStopper() {
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      stopper.toggle();
      stopped = !stopped;
  }
}

// Color sorting
void Intake::color_sort() {
    coloring.set_led_pwm(50);
    if (coloring.get_hue() >= 0.0 && coloring.get_hue() <= 30.0 && !red) {
        pros::lcd::print(4, "nihao1");
        if (distance.get_object_velocity() > 0.05 || distance2.get_object_velocity() > 0.05) {
            sorter.extend();
            pros::delay(100);
            sorter.retract();
        }
    } 
    else if (coloring.get_hue() >= 180.0 && coloring.get_hue() <= 240.0 && red) {
        if (distance.get_object_velocity() > 0.05 || distance2.get_object_velocity() > 0.05) {
            sorter.extend();
            pros::delay(100);
            sorter.retract();
        }
    }

}
// Double parking 
void Intake::park() {
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      doublePark.toggle();
  }
}