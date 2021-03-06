#include "subsystem/OtherManip.hpp"
using namespace ctre::phoenix::motorcontrol;

// Configure Hardware Settings
OtherManip::OtherManip()
{
    motorB1PWM.SetInverted(false);
    motorB2PWM.SetInverted(false);
    motorB1.SetInverted(false);
    motorB2.SetInverted(false);

    motorB1.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
    motorB1.ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_25Ms, 0);
    motorB1.ConfigVelocityMeasurementWindow(32, 0);
    motorB1.SetStatusFramePeriod(ctre::phoenix::motorcontrol::StatusFrameEnhanced::Status_3_Quadrature, 3, 100);
}

void OtherManip::Deploy()
{
    solenoidArmB.Set(true);
}

void OtherManip::Retract()
{
    solenoidArmB.Set(false);
}

void OtherManip::Stop()
{
    motorsB.StopMotor();
}

void OtherManip::Forward()
{
    motorsB.Set(kMotorSpeed);
}

void OtherManip::Backward()
{
    motorsB.Set(-kMotorSpeed);
}

bool OtherManip::SolenoidState(){
    return solenoidArmB.Get();
}

void OtherManip::SolenoidToggle(){
    bool PCM2 = SolenoidState();
    solenoidArmB.Set(!PCM2);
}

bool OtherManip::GetFwdLim()
{
    return motorB1.GetSensorCollection().IsFwdLimitSwitchClosed() != 0;
}

bool OtherManip::GetRevLim()
{
    return motorB1.GetSensorCollection().IsRevLimitSwitchClosed() != 0;
}
void OtherManip::UpdateSmartdash()
{
    SmartDashboard::PutNumber("auxMotorB", motorsB.Get());
    SmartDashboard::PutNumber("auxSolenoidB", solenoidArmB.Get());
}