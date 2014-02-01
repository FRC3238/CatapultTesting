#ifndef CATAPULT_H
#define CATAPULT_H

#include <WPILib.h>
#include "Settings.h"
#include "InsightLT_CPP/InsightLT.h"
using namespace insight;

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
		Encoder *encoder;
		InsightLT insight;
		IntegerData insight_encoderCount;
		DriverStation *DS;
		DriverStationEnhancedIO &DSEIO;
};

#endif
