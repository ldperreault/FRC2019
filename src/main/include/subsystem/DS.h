#pragma once

#include <SmartDashboard/SmartDashboard.h>
#include <SmartDashboard/SendableChooser.h>
#include <LiveWindow/LiveWindow.h>
#include <XboxController.h>
#include <CameraServer.h>
#include "PS4Controller.h"

using namespace llvm;

class DS
{
    public:
    XboxController DriverXB{3};
    XboxController OperatorXB{4};

    PS4Controller DriverPS{0};
    PS4Controller OperatorPS{1};

    cs::UsbCamera cam0 = CameraServer::GetInstance()->StartAutomaticCapture("Camera 0", 0);
    cs::VideoSink server = CameraServer::GetInstance()->GetServer();
    cs::CvSink sink0;
    LiveWindow& m_lw = *frc::LiveWindow::GetInstance();

    SendableChooser<llvm::StringRef> chooseController;
		const llvm::StringRef sPS4 = "PS4";
		const llvm::StringRef sXBX = "Xbox";

    DS();
};