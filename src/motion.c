#include "motion.h"

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

void driveDistance(int distance){

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

void armsDistance(int distance){

}

//Lift
int lift(int power){
	motor[liftLeft] = motor[liftRight] = power;
	return power;
}

void liftDistance(int distance){

}

//Intake
int intake(int power){
	motor[coneIntake]	= power;
	return power;
}
