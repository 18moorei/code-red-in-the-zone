task autonomous(){
	//Checks if autonomous is enabled and should run
	//Don't run autonomous if the power expander has no battery, so we can touch it and replace it
	if(SensorValue[autonomousToggle]||SensorValue[powerExpander]<300){return;}

	//Enable PID control
	pidEnabled(true);

	//Move arms out of the way
	arm(-127);
	wait1Msec(500);
	arm(-ARM_LOCK);

	//Drive backwards to mobile goal
	drive(-127);
	waitUntil(SensorValue[aclY] > 20);
	drive(0); //Don't hold motors

	//Pickup mobile goal
	mogo(-MAX_POWER);
	wait(1);

	//Slam preload on top
	arm(0); //Stop locking arms so the cone can coast down
	wait(1);
	intake(-127);
	wait1Msec(1000);
	intake(0);

	//Drive back to the start
	forward(2000, degrees, 127);

	turnRight(666, degrees); //Turn around
	backward(1000, degrees, 67);
	mogo(127);
	forward(1000, degrees, 67);
	wait1Msec(500);

	//Stop
	allMotorsOff();
}
