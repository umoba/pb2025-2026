#include "main.h"
#include "globals.h"// IWYU pragma: keep
#include "lemlib/pid.hpp"
#include "pros/rtos.hpp"
#include "subs_headers/intakes.h"
#include "subs_headers/tongue.h"
#include "auton.h"
using namespace Robot;
using namespace Robot::Globals;
#include "lemlib/api.hpp" // IWYU pragma: keep

Auton::Auton() {}
//----------------------------------------------------------------------------------------------------------

//good team mate versions
    //v1
//left --> one goal (long goal): 9
void leftOne(){
    chassis.setPose(0, 0, 0);
    filteredIMU.set_heading(0);
    
    // chassis.moveToPose();
    pros::delay(2000);
    tongue.extend();
    chassis.moveToPoint(20,-20, 100);



}

//right (flip left)
void rightOne(){

}

    //v2
//left --> loader first, 2 goals, no under: 7
void leftLoadFirst(){

}

//right (flip left)
void rightLoadFirst(){

}

    //v3
//left --> loader second, 2 goals, no under: 7
void leftLoadSecond(){

}

//right (flip left)
void rightLoadSecond(){

}

    //v4
//left --> 2 goals, w/ under: 9
void leftUnder(){
    
}

//right (flip left)
void rightUnder(){

}

//----------------------------------------------------------------------------------------------------------

//bad teammates version: solo auton
    //v1  --> 3 goals (2,2,6), no under: 10 
        //awp
void solo(){

}

//----------------------------------------------------------------------------------------------------------

//skills
void skills(){
    
}