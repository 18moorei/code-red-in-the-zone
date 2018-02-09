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

//Positioning
typedef struct {
	int x;
	int y;
	int z;
	int r;
} Point;

Point current_pos;
Point arm_pos;

void setHome(void) {
	//Reset bot position
	current_pos.x = 0;
	current_pos.y = 0;
	current_pos.r = 0;
	SensorValue[gyro] = current_pos.r;
	SensorScale[gyro] = 260;
	SensorFullCount[gyro] = 3600;
	SensorValue[aclX] = current_pos.x;
	SensorValue[aclY] = current_pos.y;
	SensorValue[aclZ] = current_pos.z;
	//Reset arm position
	arm_pos.y = 0;
	arm_pos.r = 0;
	SensorValue[armLiftEncoder] = arm_pos.y;
	SensorValue[armEncoder] = arm_pos.r;
}
