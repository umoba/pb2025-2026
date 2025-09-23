#pragma once
#include "pros/imu.hpp"
#include "globals.h"// IWYU pragma: keep
#include "filteredIMU.h"

using namespace Robot;
using namespace Robot::Globals;

FilteredIMU::FilteredIMU(std::uint8_t port, double alpha) : pros::Imu(port), alpha(alpha), previousHeading(0.0) {}

double FilteredIMU::getFilteredHeading() {
    double currentHeading = get_heading();
    previousHeading = alpha * currentHeading + (1 - alpha) * previousHeading;
    double roundedHeading = std::round(previousHeading * 100.0) / 100.0;
    return roundedHeading;
}

bool FilteredIMU::is_calibrating() {
    return pros::Imu::is_calibrating();
}

void FilteredIMU::reset() {
    pros::Imu::reset();
}