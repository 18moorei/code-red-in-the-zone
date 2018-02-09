task autonomousDriving();
task autonomousManipulation();

task autonomous(){
	//Checks if autonomous is enabled and should run
	//Don't run autonomous if the power expander has no battery, so we can touch it and replace it
	if(SensorValue[autonomousToggle]||SensorValue[powerExpander]<300){return;}
	stopTask(blink);

	startTask(autonomousDriving);
	startTask(autonomousManipulation);
}

bool atMogoFlag = false, atBarFlag = false;

task autonomousDriving(){
	//Drive forwards to mogo
	drive(127);
	waitUntil(SensorValue[aclY] < -5);
	wait1Msec(400);
	drive(0);
	wait1Msec(700);
	atMogoFlag = true;

	//Wait as mogo is picked up
	wait1Msec(1700);

	//Drive back to the start
	drive(-MAX_POWER/2);
	waitUntil(SensorValue[aclY] > 5);
	drive(0);
	wait1Msec(200);
	drive(MAX_POWER/2);
	wait1Msec(500);
	drive(0);

	//Deposit mogo
	int turn_goal = GYRO_SIMPLE + 90;
	while (GYRO_SIMPLE < turn_goal){
		drive(0, -55);
	}
	drive(MAX_POWER/2);
	wait1Msec(500);
	atMogoFlag = true;
	wait(2200);
	drive(-MAX_POWER);
	wait1Msec(3000);

	//Stop
	allMotorsOff();
}

task autonomousManipulation(){
	//Move arm out of the way and engage mogo
	arm(-MAX_POWER);
	mogo(MAX_POWER);
	waitUntil(SensorValue[armEncoder] > 800);
	arm(-ARM_LOCK);
	wait1Msec(500);
	mogo(0);
  waitUntil(atMogoFlag);

  //Pickup mogo
	mogo(-90);
	wait1Msec(1700);

	//Slam preload on top
	arm(60);
	wait1Msec(800);
	arm(-60);
	intake(-MAX_POWER);
	wait1Msec(800);
	mogo(0);
	arm(0);
	intake(0);
	waitUntil(atBarFlag);

	//Deposit mogo
	mogo(MAX_POWER);
	wait1Msec(1500);
	mogo(-MAX_POWER);
	wait1Msec(700);
	mogo(MAX_POWER);
}
