task autonomous(){
	//Checks if autonomous is enabled and should run
	//Don't run autonomous if the power expander has no battery, so we can touch it and replace it
	if(SensorValue[autonomousToggle]||SensorValue[powerExpander]<300){return;}

	//Enable PID
	setPIDforMotor(driveSplitLeft, true);
	setPIDforMotor(driveSplitRight, true);
	setPIDforMotor(liftRight, true);
	setPIDforMotor(armLeft, true);

	//Lift arm up a little to hold the cone out of the way
	armsPosition(-500);

	//Drive backwards to mobile goal
	backward(2000, degrees, 127);
	drive(0); //Don't hold motors

	//Pickup mobile goal
	pistons(1);
	wait(1);

	//Slam preload on top
	arms(0); //Stop locking arms so the cone can coast down
	wait(1);
	intake(-127);
	armsPosition(-500);
	intake(0);

	//Drive back to the start
	forward(2000, degrees, 127);

	turnRight(666, degrees); //Turn around
	backward(500, degrees, 12);
	pistons(0);
	forward(500, degrees, 12);

	//Stop
	allMotorsOff();
}
