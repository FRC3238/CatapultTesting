#include <WPILib.h>
#include "Catapult.h"

double motorPower;
double throwTime;
long throwClicks;
int encoderCount;

Catapult::Catapult(void) : insight(FOUR_ZONES){
	motorOneTalon = new Talon(1);
	motorTwoTalon = new Talon(2);
//	timer = new Timer();
	settings = new SettingsGetter("Settings.txt");
	encoder = new Encoder(1, 2, false);
}

void Catapult::RobotInit() {
	insight_encoderCount.setHeader("Count:");
	insight.registerData(insight_encoderCount, 1);
	insight.startDisplay();	
}
	
void Catapult::DisabledInit() {
	motorOneTalon->Set(0);
	motorTwoTalon->Set(0);
	encoder->Stop();
	encoder->Reset();
//	timer->Stop();
//	timer->Reset();
}

void Catapult::AutonomousInit() {
	encoder->Start();
//	timer->Start();
}

void Catapult::TeleopInit() {

}
	
void Catapult::DisabledPeriodic() {
	settings->rehash();
	motorPower = settings->getDouble("motorPower", 1.0, false);
	throwClicks = settings->getLong("throwClicks", 0, false);
	encoderCount = encoder->Get();
	insight_encoderCount.setData(encoderCount);
//	throwTime = settings->getDouble("throwTime", 0.0, false);
}

void Catapult::AutonomousPeriodic() {
	encoderCount = encoder->Get();
	insight_encoderCount.setData(encoderCount);
	if(encoder->Get() < throwClicks){
		motorOneTalon->Set(motorPower);
		motorTwoTalon->Set(motorPower);
	}
	else{
		motorOneTalon->Set(0);
		motorTwoTalon->Set(0);		
	}

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

}


START_ROBOT_CLASS(Catapult);
