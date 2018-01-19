#include "motion.h"

//Utilities
int threshold(int value, int threshold);
void reset_I2C_sensors(void);

//Driving
void drive(int y, int t = 0){
	//y - Forwards/Backwards
	//t - Turning (optional parameter)
	motor[driveLeftFront] = y+t;
	motor[driveRightFront] = y-t;
}

//Mogo (mobile goal lift)
void mogo(int power){
	motor[mobileGoalLeft] = power;
}

//Arm
void arm(int power){
	motor[armLeftSplit] = power;
}

//Lift
void lift(int power){
	motor[armLift] = power;
}

//Intake
void intake(int power){
	motor[coneIntake] = power;
}

//Utilities
int threshold(int value, int threshold){
	return abs(value) > abs(threshold) ? value : 0;
}

void reset_I2C_sensors(void){
	SensorValue[I2C_1] = SensorValue[I2C_2] = SensorValue[I2C_3] = SensorValue[I2C_4] = 0;
}
