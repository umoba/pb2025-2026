#pragma once

namespace Robot {

/**
 * @brief The Intake class represents a robot intake system.
 */
class Intake {
public:
   /**
    * @brief Runs the main function of the intake system.
    *
    * Takes optional user input to control the direction of the intake system in
    * autonomous.
    */
   bool red;
   bool auton;
   void intake(int state);
   void run();
   void runrev();
   void toggleStopper();
   void color_sort();
   void park();
   Intake();

private:
   // bool elevate;
   bool l2;
   bool up;
   bool dn;
   bool stopped; //stopping the intake to load
   int state;
   /**
    * @brief blue is false, red is true.
    */
};
} // namespace Robot