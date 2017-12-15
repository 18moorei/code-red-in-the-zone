#include "motion.h"

//Utilities
int threshold(int value, int threshold);
void reset_I2C_sensors(void);

//Driving
void drive(int y, int t = 0){
	//y - Forwards/Backwards
	//t - Turning (optional parameter)
	motor[driveSplitLeft] = y-t;
	motor[driveSplitRight] = y+t;
}

//Pistons
void pistons(int position){
	SensorValue[pistonLeft] = SensorValue[pistonRight] = position;
}

//Arms
void arms(int power){
	motor[armLeft] = power;  //armRight and armExtra are slaved to armLeft
}

void armsPosition(long position, int speed = 127){
	//0 is at mobile goal
	setMotorTarget(armLeft, position, speed, true);
	waitUntilMotorStop(armLeft);
}

//Lift
void lift(int power){
	motor[liftRight] = power;  //liftLeft is slaved to liftRight
}

//Intake
void intake(int power){
	motor[coneIntake] = power;
}

//Utilities
int threshold(int value, int threshold){
	return abs(value) > threshold ? value : 0;
}

void reset_I2C_sensors(void){
	SensorValue[I2C_1] = SensorValue[I2C_2] = SensorValue[I2C_3] = SensorValue[I2C_4] = 0;
}
