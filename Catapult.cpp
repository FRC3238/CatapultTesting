#include <WPILib.h>
#include "Catapult.h"

double motorPower;
double throwTime;

Catapult::Catapult(void){
	motorOneTalon = new Talon(1);
	motorTwoTalon = new Talon(2);
	timer = new Timer();
	settings = new SettingsGetter("Settings.txt");
}

void Catapult::RobotInit() {

}
	
void Catapult::DisabledInit() {
	motorOneTalon->Set(0);
	motorTwoTalon->Set(0);
	timer->Stop();
	timer->Reset();
}

void Catapult::AutonomousInit() {
	timer->Start();
}

void Catapult::TeleopInit() {

}
	
void Catapult::DisabledPeriodic() {
	settings->rehash();
	motorPower = settings->getDouble("motorPower", -1.0, false);
	throwTime = settings->getDouble("throwTime", 0.0, false);
}

void Catapult::AutonomousPeriodic() {
	if((timer->Get() * 1000.0) < throwTime){
		motorOneTalon->Set(motorPower);
		motorTwoTalon->Set(motorPower);
	}
	else{
		motorOneTalon->Set(0);
		motorTwoTalon->Set(0);
	}
}
	
void Catapult::TeleopPeriodic() {

}


START_ROBOT_CLASS(Catapult);
