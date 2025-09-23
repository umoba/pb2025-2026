#include "main.h"
#include "globals.h"// IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "robodash/api.h"
using namespace Robot;
using namespace Robot::Globals;
#include "lemlib/api.hpp" // IWYU pragma: keep
ASSET(ringTest_txt); // '.' replaced with "_" to make c++ happy

std::string selectedAuton = "";
void a() { std::cout << "Running best auton" << std::endl; }
void b() { std::cout << "Running simple auton " << std::endl; }
void c() { std::cout << "Running good auton" << std::endl; }
void d() { std::cout << "Running skills" << std::endl; }

// ================================= Views ================================= //

// Create robodash selector
rd::Selector selector({
    {"Best auton", &a, "", 0},
    {"Simple auton", &b, "", 220},
    {"Good auton", &c, "", 100},
    {"Skills", &d},
});

// Create robodash console
rd::Console console;



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

    chassis.calibrate(); // Calibrate sensors

    selector.on_select([](std::optional<rd::Selector::routine_t> routine) {
		if (routine == std::nullopt) {
			std::cout << "No routine selected" << std::endl;
		} else {
			std::cout << "Selected Routine: " << routine.value().name << std::endl;
      selectedAuton = routine.value().name;
		}
	});
    

    
    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(10);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs


    // pros::Task sortingTask Robot::Sorter::(on(void) );    

    // thread to for brain screen and position logging


     

}   

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {
  selector.focus();
}

// get a path used for pure pursuit
// this needs to be put outside a function
// ASSET(ringTest_txt); // '.' replaced with "_" to make c++ happy

/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */

void autonomous() {
  pros::Task screenTask([&]() {
    while (true) {
      console.printf("Auton: %s", selectedAuton);
      console.printf("X: %f", chassis.getPose().x); // x
      console.printf("Y: %f", chassis.getPose().y); // y
      console.printf("Theta: %f", filteredIMU.get_heading()); // Use filtered heading
      console.clear();
      // subsystem.intake.color_sort();
      pros::delay(50); // Ensure sufficient delay

          
    }
  });

  selector.run_auton();
}

/**
 * Runs in driver control
 */
void opcontrol() {
    // chassis.setPose(0, 0, 0);
    // filteredIMU.set_heading(0);
    // while (true) {
    //     // get joystick positions
    //     int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    //     int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        
    //     // move the robot
    //     chassis.tank(-rightY, -leftY);

    //     // run the subsystems
    //     subsystem.intake.run();
    //     subsystem.tongue.run();
    //     subsystem.highGoal.run();
    //     subsystem.intake.park();

        
    //     // delay to save resources
    //     pros::delay(50);
    // }
}