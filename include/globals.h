#pragma once

#include "api.h" // IWYU pragma: keep
#include "filteredIMU.h"
#include "lemlib/pid.hpp"
#include "liblvgl/misc/lv_color.h" // IWYU pragma: keep
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"



namespace Robot {
  namespace Globals {

    // Subsytems
    struct RobotSubsystems {
      Robot::Intake intake;
      Robot::Tongue tongue;
    };
    extern RobotSubsystems subsystem;

    // IMU
    struct alteredIMU {
      Robot::FilteredIMU imus;
    };
    extern FilteredIMU filteredIMU;

    // Controller
    extern pros::Controller controller;

    // Motors
    extern pros::MotorGroup intakes;
    extern pros::MotorGroup left;
    extern pros::MotorGroup right;

    // Rotational

    // Optical
    extern pros::Optical coloring;

    // Distance
    extern pros::Distance distance;
    extern pros::Distance distance2;


    // Pneumatics
    extern pros::adi::Pneumatics tongue;
    extern pros::adi::Pneumatics sorter;
    extern pros::adi::Pneumatics highGoal;
    extern pros::adi::Pneumatics stopper;
    extern pros::adi::Pneumatics doublePark;


    // Odometry wheels
    extern pros::Rotation horizontalEnc; 
    extern pros::Rotation verticalEnc;

    // Lemlib
    extern lemlib::TrackingWheel horizontal;
    extern lemlib::TrackingWheel vertical;


    extern lemlib::Drivetrain drivetrain;

    extern lemlib::ControllerSettings linearController;

    extern lemlib::ControllerSettings angularController;

    extern lemlib::OdomSensors sensors;

    extern lemlib::ExpoDriveCurve throttleCurve;

    // input curve for steer input during driver control
    extern lemlib::ExpoDriveCurve steerCurve;

    // create the chassis
    extern lemlib::Chassis chassis;
    

    
  }
}