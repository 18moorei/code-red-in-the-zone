void pre_auton(){
	bStopTasksBetweenModes = true;
}

task autonomous(){
	//Checks if autonomous is enabled and should run
	//Don't run autonomous if the power expander has no battery, so we can touch it and replace it
	if(SensorValue[autonomousToggle]||!SensorValue[powerExpander]){return;}
	//Drive backwards to mobile goal
	drive(-127);
	wait(3); //TODO: Use some sensor to determine how far to drive
	drive(0);
	//Pickup mobile goal
	pistons(1);
	wait(1);
	//Slam preload on top
	arms(-127);
	wait(2); //TODO: Use encoder to determine how far to move
	intake(-127);
	wait(.5);
	arms(127);
	wait(1);
	arms(ARM_LOCK); //Lock the arms in air so they don't get in the way
	//Drive back to the start
	drive(127);
	intake(0);
	wait(2);
	drive(127, 127); //Turn around
	wait(1);
	drive(127);
	wait(2);
	pistons(0);
	drive(-127);
	wait(2);
	//Stop
	drive(0);
	arms(0);
}