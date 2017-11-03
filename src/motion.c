#include "motion.h"

// Utilities
int threshold(int value, int threshold){
	return abs(value) > threshold ? value : 0;
}

int sign(int x) {
    return (x > 0) - (x < 0);
}

// Driving
void drive(int y, int t = 0){
	// y - Forwards/Backwards
	// t - Turning (optional parameter)
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

// Pistons
int pistons(int position){
	SensorValue[pistonLeft] = SensorValue[pistonRight] = position;
	return PISTON_POS;
}

// Arms
int arms(int power){
	motor[armLeft] = motor[armRight] = power;
	return power;
}

void armsPosition(long position, int speed = 127){
	// 0 is at mobile goal
	setMotorTarget(armLeft, -position, speed, false);
	waitUntilMotorStop(armLeft);
	arms(0);
}

// Lift
int lift(int power){
	motor[liftRight] = power;
	return power;
}

void liftPosition(long position, int speed = 127){
	// 0 is at the bottom
	setMotorTarget(liftRight, position, speed, false);
	waitUntilMotorStop(liftRight);
	lift(0);
}

// Intake
int intake(int power){
	motor[coneIntake] = power;
	return power;
}
