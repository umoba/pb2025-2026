#include "main.h"
#include "globals.h"// IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "robodash/api.h"
using namespace Robot;
using namespace Robot::Globals;
#include "lemlib/api.hpp" // IWYU pragma: keep
ASSET(ringTest_txt); // '.' replaced with "_" to make c++ happy

std::string selectedAuton = "";
void a() { 
  left.move_velocity(-100);
  right.move_velocity(-100);
  pros::delay(1000);
  left.move_velocity(0);
  right.move_velocity(0);
  std::cout << "Running best auton" << std::endl; }
void b() { 
  pros::delay(2000);
  left.move_velocity(-100);
  right.move_velocity(-100);
  pros::delay(1000);
  left.move_velocity(0);
  right.move_velocity(0);
  std::cout << "Running simple auton " << std::endl; }
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
  if (!midGoalRetract.is_extended()) {
      midGoalRetract.extend();
  }
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

  pros::Task screenTask([&]() {
    selector.run_auton();
    while (true) {
      console.printfln("X: %f", chassis.getPose().x); // x
      console.printfln("Y: %f", chassis.getPose().y); // y
      console.printfln("Theta: %f", chassis.getPose().theta); // Use filtered heading
      // subsystem.intake.color_sort();
      pros::delay(50); // Ensure sufficient delay
      console.clear();
          
    }
  });
     

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
 *  This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
// left 7
  //      wing.toggle();
  // chassis.setPose(0, 0, 0);
  // subsystem.intake.intake(3);
  // chassis.moveToPoint(8,-27, 1300, {false, 60, 0});
  // pros::delay(1250);
  // tongue.toggle();
  // pros::delay(250);
  // chassis.moveToPoint(25,0, 1350, {true, 100});
  // chassis.turnToHeading(180,950);
  // chassis.moveToPoint(25,18,1500, {false, 50, 20});
  // subsystem.intake.intake(3);
  // pros::delay(500);
  //   subsystem.intake.intake(4);
  // pros::delay(100);
  // subsystem.intake.intake(3);
  // pros::delay(2000);
  // chassis.moveToPoint(25,-31,1100, {true, 60});
  // pros::delay(800);
  // subsystem.intake.intake(0);
  // tongue.toggle();
  // chassis.moveToPoint(25,-32,1100, {true, 60});
  // pros::delay(1800);
  // subsystem.intake.intake(2);
  // pros::delay(70);
  // subsystem.intake.intake(0);
  // chassis.moveToPoint(25,-8,500, {false});
  // chassis.turnToHeading(45,300);
  // chassis.moveToPoint(13.5,-15,1000, {false});
  // chassis.turnToHeading(350,600);
  // wing.toggle();
  // chassis.moveToPoint(13.5,-25,1000, {false, 80, 55});


//  right 7
//   wing.toggle();
// chassis.setPose(0, 0, 0);
//   subsystem.intake.intake(3);
//   chassis.moveToPoint(-7,-25, 1300, {false, 55, 0});
//   pros::delay(1200);
//   tongue.toggle();
//   pros::delay(300);
//   chassis.moveToPoint(-24.5,0, 1300, {true, 100});
//   chassis.turnToHeading(180,1000);
//   chassis.moveToPoint(-24.5,16,1400, {false, 50, 20});
//   subsystem.intake.intake(3);
//   pros::delay(2500);
//   chassis.moveToPoint(-24,-25,1000, {true, 60});
//   pros::delay(950);
//   subsystem.intake.intake(0);
//   pros::delay(3000);
//   chassis.moveToPoint(-24,-35,1000, {true, 60});
//   chassis.cancelMotion();
//   tongue.toggle();
//   chassis.moveToPoint(-24,0,600, {false, 80, 30});
//   chassis.moveToPoint(-14.7,-12,700, {true, 80, 30});
//   wing.toggle();
//   chassis.moveToPoint(-14.7,-26,900, {true, 80, 47});

// left mid (NOT DONE)

  // wing.toggle();
  // chassis.setPose(0, 0, 0);
  // subsystem.intake.intake(3);
  // chassis.moveToPoint(8,-25, 1300, {false, 55, 0});
  // pros::delay(1200);
  // tongue.toggle();
  // pros::delay(250);
  // chassis.turnToHeading(225,1000);
  // chassis.moveToPoint(-9.3, -26.1, 1300, {true, 50});
  
  // chassis.turnToHeading(225,500);
  // pros::delay(1200);
  // midGoalRetract.extend();
  // subsystem.intake.intake(8);
  // midGoalRetract.toggle();
  // pros::delay(1500);
  // midGoalRetract.toggle();
  // subsystem.intake.intake(3);
  // chassis.moveToPoint(25,0, 1500, {true, 100});
  // chassis.turnToHeading(180,850);
  // chassis.moveToPoint(25,18,1300, {false, 50, 20});
  // subsystem.intake.intake(3);
  // pros::delay(2300);
  // chassis.moveToPoint(25,-31,1000, {true, 60});
  // pros::delay(800);
  // subsystem.intake.intake(0);
  // tongue.toggle();
  // chassis.moveToPoint(25,-32,1000, {true, 60});
  // pros::delay(1800);
  // subsystem.intake.intake(4);

void autonomous() {
  wing.toggle();
chassis.setPose(0, 0, 0);
  subsystem.intake.intake(3);
  chassis.moveToPoint(-7,-23.7, 1300, {false, 55, 0});
  pros::delay(900);
  tongue.toggle();
  pros::delay(300);
  chassis.moveToPoint(-24,0, 1300, {true, 100});
  chassis.turnToHeading(175,1050);
  chassis.moveToPoint(-23.5,18.3,1450, {false, 50, 23});
  subsystem.intake.intake(3);
  pros::delay(2500);
  chassis.moveToPoint(-23.5,-25,1000, {true, 60});
  pros::delay(950);
  subsystem.intake.intake(0);
  pros::delay(100);
  subsystem.intake.intake(2);
  pros::delay(80);
  subsystem.intake.intake(0);
  pros::delay(300);
  subsystem.intake.intake(2);
  pros::delay(80);
  subsystem.intake.intake(0);
  pros::delay(1000);
  subsystem.intake.intake(2);
  pros::delay(200);
  subsystem.intake.intake(0);
  pros::delay(1000);
  chassis.moveToPoint(-23.3,-35,1100, {true, 60});
  chassis.cancelMotion();
  subsystem.intake.intake(4);
  tongue.toggle();
  chassis.moveToPoint(-23.3,0,600, {false, 80, 30});
  chassis.moveToPoint(-14.7,-12,700, {true, 80, 30});
  wing.toggle();
  chassis.moveToPoint(-14.7,-24,780, {true, 80, 47});






    // chassis.swingToPoint(18, -20, right1000);


  subsystem.intake.auton = false;
  






  // selector.run_auton();
}

/**
 * Runs in driver control
 */
void opcontrol() {

    console.printf("Hello");
    while (true) {


        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        
        // move the robot
        chassis.arcade(leftY, rightX);

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
          wing.toggle();
        }
        // run the subsystems
        subsystem.intake.run();
        subsystem.tongue.run();

        // delay to save resources
        pros::delay(50);
    }
}

/*

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
void a() { 
  left.move_velocity(-100);
  right.move_velocity(-100);
  pros::delay(1000);
  left.move_velocity(0);
  right.move_velocity(0);
  std::cout << "Running best auton" << std::endl; }
void b() { 
  pros::delay(2000);
  left.move_velocity(-100);
  right.move_velocity(-100);
  pros::delay(1000);
  left.move_velocity(0);
  right.move_velocity(0);
  std::cout << "Running simple auton " << std::endl; }
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


/***
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 *//*
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

  pros::Task screenTask([&]() {
    selector.run_auton();
    while (true) {
      console.printfln("X: %f", chassis.getPose().x); // x
      console.printfln("Y: %f", chassis.getPose().y); // y
      console.printfln("Theta: %f", chassis.getPose().theta); // Use filtered heading
      subsystem.intake.color_sort();
      pros::delay(50); // Ensure sufficient delay
      console.clear();
          
    }
  });
     

}   
/*
/**
 * Runs while the robot is disabled
 */
//void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 *//*
void competition_initialize() {
  selector.focus();
}

// get a path used for pure pursuit
// this needs to be put outside a function
// ASSET(ringTest_txt); // '.' replaced with "_" to make c++ happy

/**
 * Runs during auto
 *
 *  This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
/*
void autonomous() {
  subsystem.intake.intake(3);
  chassis.moveToPoint(1,-12,600, {false});
  chassis.turnToHeading(23, 300);
  chassis.moveToPoint(-9,-27, 1500, {false, 40, 0});
  pros::delay(500);
  tongue.toggle();                                                                                                                                                                                                                             
  chassis.turnToHeading(320, 500);
  tongue.toggle();

  chassis.moveToPoint(3, -35,1500, {false, 70});
  chassis.turnToHeading(320, 500);
  subsystem.intake.intake(4);
  pros::delay(2000);

  subsystem.intake.intake(3);
  chassis.moveToPoint(-31,-10, 2000, {true, 50});
  chassis.moveToPose(-32,-31, 180,1500);
  stopper.toggle();
  tongue.toggle();
  subsystem.intake.intake(5);
  pros::delay(2000);
  subsystem.intake.intake(3);
  // stopper.toggle();
  chassis.turnToHeading(180, 300);
  chassis.moveToPoint(-31,19,1500, {false, 35});
  pros::delay(3000);
  chassis.moveToPoint(-31,-25,1000, {true, 70});
  // stopper.toggle();
  subsystem.intake.intake(5);
  // subsystem.intake.auton = false;
  






  // selector.run_auton();
}

/**
 * Runs in driver control
 *//*
void opcontrol() {
    chassis.setPose(0, 0, 0);
    filteredIMU.set_heading(0);
    console.printf("Hello");
    while (true) {
        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        
        // move the robot
        chassis.arcade(leftY, rightX);

        // run the subsystems
        subsystem.intake.run();
        subsystem.tongue.run();
        subsystem.intake.toggleStopper();

        // delay to save resources
        pros::delay(50);
    }
}
*/