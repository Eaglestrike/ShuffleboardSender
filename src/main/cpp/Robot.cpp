// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

Robot::Robot():
  shuff2_("New Sender", false) // Tab not initially enabled, constructed in class constructor 
{
}

void Robot::RobotInit() {
  // This places a double value with width 2, height 1, and position (0,0)
  // This is EDITABLE, so "number" will CHANGE based off the shuffleboard value
  shuff_.add("double value", &number, {2,1,0,0}, true);

  // This is UN-EDITABLE, so "integer" will not have its value changed
  shuff_.add("int value", &integer, {2,1,0,1}, false); 

  // This should show up as a toggle button as it is editable
  shuff_.add("bool value", &boolean, {2,2,2,0}, true); 
   // This shows the boolean value
  shuff_.add("show bool value", &boolean, {2,1,2,2});

  // This is a button, which executes the passed-in lambda when pressed
  shuff_.PutNumber("CHANGE ME", 0.0, {2,1,0,3});
  shuff_.addButton("Print Number",
                  [&]{
                    std::cout<<"CHANGE ME value: "<<shuff_.GetNumber("CHANGE ME", 0.0)<<std::endl; // lambda
                  }, {2,1,0,4});

  // This is a toggle button, with 2 different functions when on/off
  shuff_.addToggleButton("Enable other shuffleboard tab",
                    [&]{shuff2_.enable(); std::cout<<"Switched On!"<<std::endl;},     //Called when switched on
                    [&]{shuff2_.disable(); std::cout<<"Switched Off!"<<std::endl;},    //Called when switched off
                  false, {4,1,3,5});

  //Values will not be editable since shuff2_.update's EDIT is FALSE
  shuff2_.add("double value", &number, {2,2,0,0}, true);
  //Buttons will not work
  shuff2_.addButton("Button No Work", [&]{std::cout<<"I LIED BUTTON WORKS"<<std::endl;}, {2,2,2,0});

  //If you don't specify a pose location, it will be placed based off the shuffleboard default algorithm
  shuff2_.PutNumber("random location 1", 1);
  shuff2_.PutNumber("random location 2", 2, {2,1});
  shuff2_.PutNumber("random location 3", 3, {2,2});
}

void Robot::RobotPeriodic() {
  //VERY IMPORTANT DO NOT FORGET OR SHUFFLEBOARDSENDER WILL NOT WORK
  shuff_.update(true); //Updates and edits values
  shuff2_.update(false); //Updates but does not update values
}

void Robot::AutonomousInit() {
  shuff_.PutString("Mode", "Auto", {3,1,5,0}); //Will put string based on current mode
}
void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {
  shuff_.PutString("Mode", "Teleop", {3,1,5,0}); //Will put string based on current mode
}
void Robot::TeleopPeriodic() {
  //Will only appear after teleop is enabled
  shuff_.PutNumber("Time", frc::Timer::GetFPGATimestamp().value(), {3,1,5,1});
}

void Robot::DisabledInit() {
  shuff_.PutString("Mode", "Disabled", {3,1,5,0}); //Will put string based on current mode
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {
  shuff_.PutString("Mode", "Test", {3,1,5,0}); //Will put string based on current mode
}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
