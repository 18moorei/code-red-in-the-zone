#include "motion.h"

//Utilities
int threshold(int value, int threshold){
	return abs(value) > threshold ? value : 0;
}

int sign(int x) {
    return (x > 0) - (x < 0);
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

void driveDistance(long left, long right = left, int speed = 127){
	driveResetEncoders();
	setMotorTarget(driveSplitLeft, left, speed, false);
	setMotorTarget(driveSplitRight, right, speed, false);
	waitUntilMotorStop(driveSplitLeft);
	waitUntilMotorStop(driveSplitRight);
	drive(0);
}

void driveLeftTurn(int speed = 127){
	driveDistance(1000, 50, speed);
}

//Pistons
int pistons(int position){
	SensorValue[pistonLeft] = SensorValue[pistonRight] = position;
	return PISTON_POS;
}

//Arms
int arms(int power){
	motor[armLeft] = motor[armRight] = power;
	return power;
}

void armsPosition(long position, int speed = 127){
	setMotorTarget(armLeft, position, speed, false); //TODO: Check which motor it is actually on
	motor[armRight] = motor[armLeft]; //TODO: Sync the other motor to the encoded one
	waitUntilMotorStop(armLeft);
	arms(0);
}

//Lift
int lift(int power){
	motor[liftLeft] = motor[liftRight] = power;
	return power;
}

void liftPosition(long position, int speed = 127){
	setMotorTarget(liftLeft, position, speed, false); //TODO: Check which motor it is actually on
	motor[liftRight] = motor[liftLeft]; //TODO: Sync the other motor to the encoded one
	waitUntilMotorStop(liftLeft);
	lift(0);
}

//Intake
int intake(int power){
	motor[coneIntake]	= power;
	return power;
}
