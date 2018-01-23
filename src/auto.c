task autonomous(){
	//Checks if autonomous is enabled and should run
	//Don't run autonomous if the power expander has no battery, so we can touch it and replace it
	if(SensorValue[autonomousToggle]||SensorValue[powerExpander]<300){return;}

	//Enable PID control
	pidEnabled(false); //Disabled until we can figure out why PID is broken

	//Move arm out of the way
	arm(-MAX_POWER);
	mogo(MAX_POWER);
	wait1Msec(200);
	arm(-ARM_LOCK);

	//Drive backwards to mobile goal
	drive(-127);
	waitUntil(SensorValue[aclY] < -5);
	drive(0);
	wait(1);

	//Pickup mobile goal
	mogo(-90);
	wait(2);

	//Slam preload on top
	arm(60);
	wait(1);
	arm(-60);
	intake(MAX_POWER);
	wait(1);
	mogo(0);
	arm(0);
	intake(0);

	//Drive back to the start
	drive(MAX_POWER);
	waitUntil(SensorValue[aclY] > 5);
	drive(-MAX_POWER/2);
	wait1Msec(500);
	drive(0);

	//Deposit mobile goal
	int turn_goal = GYRO_SIMPLE + 90;
	while (GYRO_SIMPLE < turn_goal){
		drive(0, -40);
	}
	drive(-30);
	mogo(127);
	wait(2);
	drive(30);
	wait(3);

	//Stop
	allMotorsOff();
}
