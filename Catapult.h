#ifndef CATAPULT_H
#define CATAPULT_H

#include <WPILib.h>
#include "Settings.h"

class Catapult : public IterativeRobot {
	
	public:
		Catapult(void);
		void RobotInit(void);
		void DisabledInit(void);
		void DisabledPeriodic(void);
		void AutonomousInit(void);
		void AutonomousPeriodic(void);
		void AutonomousContinuous(void);
		void TeleopInit(void);
		void TeleopPeriodic(void);
	
	private:
		Talon *motorOneTalon;
		Talon *motorTwoTalon;
		Timer *timer;
		SettingsGetter *settings;
};

#endif
