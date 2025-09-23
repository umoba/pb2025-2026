#include "globals.h"// IWYU pragma: keep
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
// #include "tasks_headers/activator.h"


namespace Robot {
  
  namespace Globals {
    // Subsystems
    RobotSubsystems subsystem;

    // IMU
    FilteredIMU filteredIMU(17,0.9);

    // Controller
    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    // Motors
    pros::MotorGroup left({-8, -12, -13},pros::MotorGearset::blue);
    pros::MotorGroup right({3, 2, 7},pros::MotorGearset::blue);
    pros::MotorGroup intakes({1, 2},pros::MotorGearset::blue);

    // Rotational

    // Optical
    pros::Optical coloring(10);

    // Distance
    pros::Distance distance(5);
    pros::Distance distance2(16);

    // Pneumatics
    pros::adi::Pneumatics tongue('A',false);
    pros::adi::Pneumatics sorter('B',false);
    pros::adi::Pneumatics highGoal('C',false);
    pros::adi::Pneumatics stopper('D',false);
    pros::adi::Pneumatics doublePark('E',false);





    // Odometry wheels
    // horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
    pros::Rotation horizontalEnc(-11);
    // vertical tracking wheel encoder. Rotation sensor, port 11, reversed
    pros::Rotation verticalEnc(15);


    // lemlib

    // horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
    lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -1.375);
    // vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
    lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_275, 1.18);

   
    // drivetrain settings
    lemlib::Drivetrain drivetrain(&left, // left motor group
      &right, // right motor group
      11.25, // 10 inch track width
      lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
      450, // drivetrain rpm is 360
      8 // horizontal drift is 2. If we had traction wheels, it would have been 8
    );

    // lateral PID controller
    lemlib::ControllerSettings lateral_controller(9, // proportional gain (kP)
                                                0.5, // integral gain (kI)
                                                18, // derivative gain (kD)
                                                2, // anti windup
                                                0.25, // small error range, in inches
                                                100, // small error range timeout, in milliseconds
                                                0.5, // large error range, in inches
                                                200, // large error range timeout, in milliseconds
                                                0 // maximum acceleration (slew)
    );

    // angular PID controller
    lemlib::ControllerSettings angular_controller(3.9, // proportional gain (kP)
                                                0, // integral gain (kI)
                                                23, // derivative gain (kD)
                                                1, // anti windup
                                                0.25, // small error range, in inches
                                                50, // small error range timeout, in milliseconds
                                                0.5, // large error range, in inches
                                                100, // large error range timeout, in milliseconds
                                                0 // maximum acceleration (slew)
    );

    // sensors for odometry
    lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
        nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
        &horizontal, // horizontal tracking wheel
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &filteredIMU // inertial sensor
    );

    // input curve for throttle input during driver control
    lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                10, // minimum output where drivetrain will move out of 127
                1.7 // expo curve gain
    );

    // input curve for steer input during driver control
    lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
              10, // minimum output where drivetrain will move out of 127
              1.7 // expo curve gain
    );

    // create the chassis
    lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttleCurve, &steerCurve);



  }
}
  