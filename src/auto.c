void pre_auton(){
	bStopTasksBetweenModes = true;
}

task autonomous(){
	//Checks if autonomous is enabled and should run
	//Don't run autonomous if the power expander has no battery, so we can touch it and replace it
	if(SensorValue[autonomousToggle]||!SensorValue[powerExpander]){return;}
	drive(-127);
	wait(3);
	drive(0);
}
