// #include "main.h"
// #include "globals.h"// IWYU pragma: keep
// #include "lemlib/pid.hpp"
// #include "pros/rtos.hpp"
// #include "subs_headers/intakes.h"
// #include "subs_headers/tongue.h"
// #include "auton.h"
// using namespace Robot;
// using namespace Robot::Globals;
// #include "lemlib/api.hpp" // IWYU pragma: keep

// Auton::Auton() {}
// //----------------------------------------------------------------------------------------------------------

// //good team mate versions
//     //v1
// //left --> one goal (long goal): 9
// void leftOne(){
//   chassis.setPose(0, 0, 0);
//   filteredIMU.set_heading(0);

//   // chassis.moveToPose();
//   pros::delay(2000);
//   tongue.extend();
//   chassis.moveToPoint(20, -20, 100);



// }

// //right (flip left)
// void rightOne(){
//   chassis.moveToPoint(0, 0, 5000);
// chassis.moveToPoint(25.481, 7.216, 5000);
// chassis.moveToPoint(-10.147, 31.795, 5000);
// chassis.moveToPoint(22.775, 32.472, 5000);

// }

//     //v2
// //left --> loader first, 2 goals, no under: 7
// void leftLoadFirst(){

// }

// //right (flip left)
// void Auton::right7blocks(){
//     // (RIGHT 7BLOCKS)
//   subsystem.intake.intake(3);
//   chassis.moveToPoint(1,-12,700, {false});
//   chassis.turnToHeading(23, 300);
//   chassis.moveToPoint(-9,-27, 2000, {false, 40, 0});
//   pros::delay(500);
//   tongue.toggle();
//   chassis.turnToHeading(310, 500);
//   chassis.moveToPoint(-33,-10, 1500, {true, 50});
//   chassis.moveToPose(-33,-29, 180,1200);
//   stopper.toggle();
//   pros::delay(1000);
//   subsystem.intake.intake(5);
//   pros::delay(3000);
  
//   subsystem.intake.intake(3);
//   // stopper.toggle();
//   chassis.moveToPose(-33,18, 180,1500, {false});
//   pros::delay(3000);
//   chassis.moveToPoint(-32,-25,1200, {true, 70});
//   // stopper.toggle();
//   subsystem.intake.intake(5);
// }

//     //v3
// //left --> loader second, 2 goals, no under: 7
// void leftLoadSecond(){

// }

// //right (flip left)
// void rightLoadSecond(){

// }

//     //v4
// //left --> 2 goals, w/ under: 9
// void leftUnder(){
    
// }

// //right (flip left)
// void rightUnder(){

// }

// //----------------------------------------------------------------------------------------------------------

// //bad teammates version: solo auton
//     //v1  --> 3 goals (2,2,6), no under: 10 
//         //awp
// void solo(){

// }

// //----------------------------------------------------------------------------------------------------------

// //skills
// void skills(){
    
// }

// void leftBottom(){
//     chassis.setPose(-58.296,-15.846, 0);

// }