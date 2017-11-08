#include "motion.h"

//Utilities
int threshold(int value, int threshold);
int sign(int x);
int required_sign(int current, int low, int high);
void reset_I2C_sensors(void);

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
	int rsign = required_sign(nMotorEncoder[armLeft], -1800, 100);
	if(sign(power) == rsign || !rsign){
		motor[armLeft] = power;  //armRight is slaved to armLeft
	} else {
		motor[armLeft] = 0;
	}
}

void armsPosition(long position, int speed = 127){
	//0 is at mobile goal
	setMotorTarget(armLeft, position, speed, true);
	waitUntilMotorStop(armLeft);
}

//Lift
void lift(int power){
	int rsign = required_sign(nMotorEncoder[liftRight], 0, 1400);
	if(sign(power) == rsign || !rsign){
		motor[liftRight] = power;  //liftLeft is slaved to liftRight
	} else {
		motor[liftRight] = 0;
	}
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

//Utilities
int threshold(int value, int threshold){
	return abs(value) > threshold ? value : 0;
}

int sign(int x){
  return (x > 0) - (x < 0);
}

int required_sign(int current, int low, int high){
	return (current < low) - (current > high);
}

void reset_I2C_sensors(void){
	SensorValue[I2C_1] = SensorValue[I2C_2] = SensorValue[I2C_3] = SensorValue[I2C_4] = 0;
}
