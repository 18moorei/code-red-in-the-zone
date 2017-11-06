#include "motion.h"

//Utilities
int threshold(int value, int threshold){
	return abs(value) > threshold ? value : 0;
}

//Driving
void drive(int y, int t = 0){
	//y - Forwards/Backwards
	//t - Turning (optional parameter)
	motor[driveSplitLeft] = y-t;
	motor[driveSplitRight] = y+t;
}

void driveResetEncoders(){
	SensorValue[driveLeftEncoder] = SensorValue[driveRightEncoder] = 0;
}

void driveDistance(int left, int right, int speed = 67){
	driveResetEncoders();
	setMotorTarget(driveSplitLeft, left, speed, false);
	setMotorTarget(driveSplitRight, right, speed, false);
	waitUntilMotorStop(driveSplitLeft);
	waitUntilMotorStop(driveSplitRight);
	drive(0);
}

//Pistons
void pistons(int position){
	SensorValue[pistonLeft] = SensorValue[pistonRight] = position;
}

//Arms
void arms(int power){
	motor[armLeft] = power;  //armRight is slaved to armLeft
}

void armsPosition(long position, int speed = 127){
	//0 is at mobile goal
	setMotorTarget(armLeft, -position, speed, true);
	waitUntilMotorStop(armLeft);
}

//Lift
void lift(int power){
	motor[liftRight] = power;  //liftLeft is slaved to liftRight
}

void liftPosition(long position, int speed = 127){
	//0 is at the bottom
	setMotorTarget(liftRight, position, speed, false);
	waitUntilMotorStop(liftRight);
	lift(0);
}

//Intake
void intake(int power){
	motor[coneIntake] = power;
}
