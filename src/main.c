#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    powerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl1,  autonomousToggle, sensorDigitalIn)
#pragma config(Sensor, dgtl11, pistonLeft,     sensorDigitalOut)
#pragma config(Sensor, dgtl12, pistonRight,    sensorDigitalOut)
#pragma config(Sensor, I2C_1,  armEncoder,     sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  liftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  driveRightEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  driveLeftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           coneIntake,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           armLeft,       tmotorVex393_MC29, PIDControl, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port4,           liftLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           driveSplitLeft, tmotorVex393_MC29, PIDControl, reversed, driveLeft, encoderPort, I2C_4)
#pragma config(Motor,  port6,           driveSplitRight, tmotorVex393_MC29, PIDControl, driveRight, encoderPort, I2C_3)
#pragma config(Motor,  port7,           liftRight,     tmotorVex393_MC29, PIDControl, encoderPort, I2C_2)
#pragma config(Motor,  port8,           armRight,      tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(105)

#include "Vex_Competition_Includes.c"
#include "NatLang_CORTEX.c"
#include "motion.c"
#include "user.c"
#include "auto.c"

void pre_auton(void){
	bStopTasksBetweenModes = true;
	//Extend pistons
	pistons(0);
	//Establish slave and master motors
	slaveMotor(armRight, armLeft);
	slaveMotor(liftLeft, liftRight);
	//Reset all encoders
	reset_I2C_sensors();
}
