#include "motion.h"

//Utilities
int threshold(int value, int threshold);
int sign(int x);
int required_sign(int current, int low, int high);
void reset_I2C_sensors(void);

//Driving
void drive(int y, int t = 0, int x = 0){
	//y - Forwards/Backwards
	//t - Turning (optional parameter)
	motor[driveLeftFront] = y+t;
	motor[driveRightFront] = y-t;
	motor[driveCenter] = x;
}

//Mogo (mobile goal lift)
void mogo(int power){
	motor[mogoLeft] = power;
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
