#include "globals.h"// IWYU pragma: keep
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/imu.hpp"
// #include "tasks_headers/activator.h"


namespace Robot {
  
  namespace Globals {
    // Subsystems
    RobotSubsystems subsystem;

    // IMU
    pros::Imu imu(13);
    // FilteredIMU filteredIMU(15,0.9);
// 
    // Controller
    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    // Motors
    pros::MotorGroup right({3, -1, 2},pros::MotorGearset::blue);
    pros::MotorGroup left({5, -4, 6},pros::MotorGearset::blue);
    // pros::MotorGroup intakes({10, 20},pros::MotorGearset::blue);
    pros::Motor firstIntake(11, pros::MotorGearset::blue);
    pros::Motor hoodIntake(-10, pros::MotorGearset::blue);
    // pros::Motor goalIntake(19, pros::MotorGearset::green);
    // pros::Motor flexIntake(-18, pros::MotorGearset::green);


    // Rotational

    // Optical
    // pros::Optical coloring(3);

    // // Distance
    // pros::Distance distance(5);
    // pros::Distance distance2(16);

    // Pneumatics
    pros::adi::Pneumatics tongue('C',false);
    pros::adi::Pneumatics wing('B',false);
    
    // pros::adi::Pneumatics sorter('D',false);
    // pros::adi::Pneumatics highGoal('C',false);
    // pros::adi::Pneumatics doublePark('E',false);
    pros::adi::Pneumatics midGoalRetract('A', true);




    // Odometry wheels
    // horizontal tracking wheel encoder. Rotation sensor, port 20, not reversed
    // pros::Rotation horizontalEnc(-11);
    // vertical tracking wheel encoder. Rotation sensor, port 11, reversed
    pros::Rotation verticalEnc(12);


    // lemlib

    // horizontal tracking wheel. 2.75" diameter, 5.75" offset, back of the robot (negative)
    // lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_275, -1.375);
    // vertical tracking wheel. 2.75" diameter, 2.5" offset, left of the robot (negative)
    lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_2, 1.0);

   
    // drivetrain settings
    lemlib::Drivetrain drivetrain(&left, // left motor group
      &right, // right motor group
      10.8, // 10 inch track width
      lemlib::Omniwheel::NEW_325, // using new 3.25" omnis
      450, // drivetrain rpm is 360
      8 // horizontal drift is 2. If we had traction wheels, it would have been 8
    );

    // lateral PID controller
    lemlib::ControllerSettings lateral_controller(11, // proportional gain (kP)
                                                0, // integral gain (kI)
                                                30, // derivative gain (kD)
                                                0, // anti windup
                                                0, // small error range, in inches
                                                0, // small error range timeout, in milliseconds
                                                0, // large error range, in inches
                                                0, // large error range timeout, in milliseconds
                                                0 // maximum acceleration (slew)
    );

    // angular PID controller
    lemlib::ControllerSettings angular_controller(5, // proportional gain (kP)
                                                0, // integral gain (kI)
                                                30, // derivative gain (kD)
                                                0, // anti windup
                                                0, // small error range, in inches
                                                0, // small error range timeout, in milliseconds
                                                0, // large error range, in inches
                                                0, // large error range timeout, in milliseconds
                                                0 // maximum acceleration (slew)
    );

    // sensors for odometry
    lemlib::OdomSensors sensors(&vertical, // vertical tracking wheel
        nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
        nullptr, // horizontal tracking wheel
        nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
        &imu // inertial sensor
    );

    // input curve for throttle input during driver control
    lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                10, // minimum output where drivetrain will move out of 127
                1.7 // expo curve gain
    );

    // input curve for steer input during driver control
    lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
              3, // minimum output where drivetrain will move out of 127
              1 // expo curve gain
    );

    // create the chassis
    lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors, &throttleCurve, &steerCurve);



  }
}
  