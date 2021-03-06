#pragma once

#include <frc/VictorSP.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Solenoid.h>
//#include <ctre/phoenix/MotorControl/CAN/WPI_VictorSPX.h>
//#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/Phoenix.h>
#include <frc/VictorSP.h>

using namespace frc;
using namespace ctre::phoenix::motorcontrol::can;

class OtherManip
{
private:
  // Hardware setup
  VictorSP motorB1PWM{8};
  VictorSP motorB2PWM{9};

  WPI_TalonSRX motorB1{8};
  WPI_VictorSPX motorB2{9};
  SpeedControllerGroup motorsB{motorB1PWM, motorB2PWM, motorB1, motorB2};

  Solenoid solenoidArmB{2};

  const double kMotorSpeed = 1.0;

public:
  // Default Constructor
  OtherManip();

  // Actions
  void Deploy();
  void Retract();

  void Forward();
  void Backward();
  void Stop();
  void SolenoidToggle();
  bool SolenoidState();
  
  bool GetFwdLim();
  bool GetRevLim();

  void UpdateSmartdash();
};