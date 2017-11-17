task autonomous(){
	//Checks if autonomous is enabled and should run
	//Don't run autonomous if the power expander has no battery, so we can touch it and replace it
	if(SensorValue[autonomousToggle]||SensorValue[powerExpander]<300){return;}

	//Stop
	allMotorsOff();
}
