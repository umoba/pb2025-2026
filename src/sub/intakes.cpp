// #include "main.h"
#include "subs_headers/intakes.h"

#include "globals.h"// IWYU pragma: keep
#include "pros/misc.h"

using namespace Robot;
using namespace Robot::Globals;


Intake::Intake() : l1(false), l2(false), up(false), stopped(false), state(0) {}

bool red = false;
static bool elevate;
const int all = 4;
static int states[4] = {1, 2, 3, 4};
int state = -1;
void intake(int state) {
  // high goal
  if (state == 0) {
    firstIntake.move_velocity(200);
    midIntake.move_velocity(200);
    goalIntake.move_velocity(200);
    flexIntake.move_velocity(200);
  }
  // mid goal
  else if (state == 1) {
    firstIntake.move_velocity(200);
    midIntake.move_velocity(200);
    goalIntake.move_velocity(200);
    flexIntake.move_velocity(-100);
  }
  // low goal
  else if (state == 2) {
    firstIntake.move_velocity(-150);
    midIntake.move_velocity(-200);
    goalIntake.move_velocity(-200);
    flexIntake.move_velocity(-200);
  }

  // storage
  else if (state == 3) {
    firstIntake.move_velocity(200);
    midIntake.move_velocity(-200);
    goalIntake.move_velocity(-200);
    flexIntake.move_velocity(-200);
  }
  // outtake from storage ((leave system)) 
  else if (state == 4) {
    firstIntake.move_velocity(-200);
    midIntake.move_velocity(200);
    goalIntake.move_velocity(0);
    flexIntake.move_velocity(0);
  }
    // outtake to scoring high goal
  else if (state == 5) {
    firstIntake.move_velocity(-100);
    midIntake.move_velocity(200);
    goalIntake.move_velocity(200);
    flexIntake.move_velocity(200);

  }
  // stop
  else if (state == 6) {
    firstIntake.move_velocity(0);
    midIntake.move_velocity(0);
    goalIntake.move_velocity(0);
    flexIntake.move_velocity(0);
  }
}


void intakeState(int a) {
  
}

// Run the intake
void Intake::run() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intake(0);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intake(1);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
    intake(3);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    intake(2);
  }
  else intake(6);

  
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