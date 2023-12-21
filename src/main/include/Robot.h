// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>

#include "ShuffleboardSender/ShuffleboardSender.h"
#include "Util/thirdparty/simplevectors.hpp"
#include "Util/ShuffleboardItems/SI_Vector.hpp"

class Robot : public frc::TimedRobot {
  public:
    Robot();

    void RobotInit() override;
    void RobotPeriodic() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void DisabledInit() override;
    void DisabledPeriodic() override;

    void TestInit() override;
    void TestPeriodic() override;

    void SimulationInit() override;
    void SimulationPeriodic() override;
  private:
    ShuffleboardSender shuff_{"Sample"}; // Tab will be created called "Sample", constructed in header
    ShuffleboardSender shuff2_; //Constructed in class construtor

    double number = 1;
    bool boolean = false;
    int integer = 0;
    std::string string = "string";

    svector::Vector2D vector = {3, 5};
};
