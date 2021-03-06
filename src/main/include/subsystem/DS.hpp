#pragma once

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/XboxController.h>
#include <cameraserver/CameraServer.h>
#include "PS4Controller.hpp"
#include <String>

using namespace frc;

class DS
{
    public:
    XboxController DriverXB{0};
    XboxController OperatorXB{1};

    PS4Controller DriverPS{0};
    PS4Controller OperatorPS{1};

    cs::UsbCamera cam0 = CameraServer::GetInstance()->StartAutomaticCapture("Camera 0", 0);
    cs::VideoSink server = CameraServer::GetInstance()->GetServer();
    cs::CvSink sink0;
    LiveWindow& m_lw = *frc::LiveWindow::GetInstance();

    SendableChooser<std::string> chooseController;
		const std::string sPS4 = "PS4";
		const std::string sXBX = "Xbox";

    DS();
};