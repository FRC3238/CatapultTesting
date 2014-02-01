#include <WPILib.h>
#include "Catapult.h"

double motorPower;
double throwTime;
double throwClicks;
int encoderCount;

Catapult::Catapult(void) : DS(DriverStation::GetInstance()),DSEIO(DS->GetEnhancedIO()), insight(FOUR_ZONES){
	motorOneTalon = new Talon(1);
	motorTwoTalon = new Talon(2);
//	timer = new Timer();
	settings = new SettingsGetter("settings.txt");
	encoder = new Encoder(1, 2, false);
}

void Catapult::RobotInit() {
	insight_encoderCount.setHeader("Count:");
	insight.registerData(insight_encoderCount, 1);
	insight.startDisplay();
	encoder->Start();
}
	
void Catapult::DisabledInit() {
	motorOneTalon->Set(0);
	motorTwoTalon->Set(0);
	encoder->Reset();
//	timer->Stop();
//	timer->Reset();
}

void Catapult::AutonomousInit() {

}

void Catapult::TeleopInit() {
	encoder->Reset();
//	timer->Start();
}
	
void Catapult::DisabledPeriodic() {
//	settings->rehash();
//	motorPower = settings->getDouble("motorPower", 0.0, false);
//	throwClicks = settings->getDouble("throwClicks", 10.0, false);
	motorPower = .60;
	throwClicks = 190;
	encoderCount = encoder->Get();
	insight_encoderCount.setData(encoderCount);
//	throwTime = settings->getDouble("throwTime", 0.0, false);
}

void Catapult::AutonomousPeriodic() {
/*	if((timer->Get() * 1000.0) < throwTime){
		motorOneTalon->Set(motorPower);
		motorTwoTalon->Set(motorPower);
	}
	else{
		motorOneTalon->Set(0);
		motorTwoTalon->Set(0);
	}
*/
}
	
void Catapult::TeleopPeriodic() {
	encoderCount = encoder->Get();
	insight_encoderCount.setData(encoderCount);
	if(DS->GetDigitalIn(2)){
		if(encoderCount < throwClicks){
			motorOneTalon->Set(motorPower);
			motorTwoTalon->Set(motorPower);
		}
		else{
			motorOneTalon->Set(0);
			motorTwoTalon->Set(0);
			motorPower = 0.0;
		}
	}
	else{
		motorOneTalon->Set(0);
		motorTwoTalon->Set(0);
		motorPower = 0.0;
	}
}


START_ROBOT_CLASS(Catapult);
