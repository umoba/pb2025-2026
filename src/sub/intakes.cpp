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
  // OVERALL INTAKE FUNCTIONS
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
  // outtake from storage to low) 
  else if (state == 4) {
    firstIntake.move_velocity(-200);
    midIntake.move_velocity(150);
    goalIntake.move_velocity(-200);
    flexIntake.move_velocity(-200);
  }
    // outtake to scoring high goal
  else if (state == 5) {
    firstIntake.move_velocity(20);
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
  // outtake to score upper 
  else if (state == 7) {
    firstIntake.move_velocity(20);
    midIntake.move_velocity(200);
    goalIntake.move_velocity(200);
    flexIntake.move_velocity(-200);

  }

  // COLOR SENSOR FUNCTIONS

  else if (state == 8) {
    
  }

  else if (state == 9) {
    
  }

  else if (state == 10) {
    
  }

 }


void intakeState(int a) {
  
}

// Run the intake
void Intake::run() {
  // Score high goal

    // to or from storage
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    // high goal
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      intake(5);
    }
    // upper goal
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      intake(7);
    }
    // storage to low
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      intake(4);
    }
    else intake(3);
  }
  // score long goal
  else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intake(0);
  }
  // Score upper goal
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    intake(1);
  }
  // score low goal
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    intake(2);
  }
  // pause
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

        }
    } 
    else if (coloring.get_hue() >= 180.0 && coloring.get_hue() <= 240.0 && red) {
        if (distance.get_object_velocity() > 0.05 || distance2.get_object_velocity() > 0.05) {
          
        }
    }

}
// Double parking 
void Intake::park() {
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      doublePark.toggle();
  }
}