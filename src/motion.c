#include "motion.h"

//Utilities
int threshold(int value, int threshold);

//Driving
void drive(int y, int t = 0){
	//y - Forwards/Backwards
	//t - Turning (optional parameter)
	motor[driveLeftRear] = y+t;
	motor[driveRightRear] = y-t;
}

//Mogo (mobile goal lift)
void mogo(int power){
	motor[mobileGoalLeft] = power;
}

//Arm
void arm(int power){
	motor[armLeftSplit] = motor[armRightSplit] = power;
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
