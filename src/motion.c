#include "motion.h"

//Utilities
int threshold(int value, int threshold);

//Driving
void drive(int y, int t = 0){
	//y - Forwards/Backwards
	//t - Turning (optional parameter)
	motor[driveLeftRear] = y-t;
	motor[driveRightRear] = y+t;
}

//Mogo (mobile goal lift)
void mogo(int power){
	motor[mobileGoalLeft] = power;
}

//Arm
void arm(int power){
	motor[armRightSplit] = power;
}

void setArmPosition(int position, int speed = MAX_POWER, bool hold = true){
	setMotorTarget(armRightSplit, position, speed, hold);
}

//Lift
void lift(int power){
	motor[armLift] = power;
}

void setLiftPosition(int position, int speed = MAX_POWER, bool hold = true){
	setMotorTarget(armLift, position, speed, hold);
}

//Intake
void intake(int power){
	motor[coneIntake] = power;
}

//Utilities
int threshold(int value, int threshold){
	return abs(value) > abs(threshold) ? value : 0;
}

//Positioning
void setHome(void) {
	//Reset bot position
	SensorValue[gyro] = 0;
	SensorScale[gyro] = 260;
	SensorFullCount[gyro] = 3600;
	SensorValue[aclX] = 0;
	SensorValue[aclY] = 0;
	SensorValue[aclZ] = 0;
	//Reset arm position
	SensorValue[armLiftEncoder] = 0;
	SensorValue[armEncoder] = 0;
}
