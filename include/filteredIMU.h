#pragma once
#include "pros/imu.hpp"


namespace Robot {

class FilteredIMU : public pros::Imu {
  public:
     /**
      * @brief Filters the value given by Imu by rounding and using an alpha variable to smoothen the sensor.
      *
      */
     double getFilteredHeading();
  
     bool is_calibrating();
  
    FilteredIMU(std::uint8_t port, double alpha = 0.9);
     void reset();
    private:
    double previousHeading;
    double alpha;
  };

} // namespace Robot