task usercontrol(){
	int DY, DT;
	bool armsLocked = false;
	while(true){
		//Driving
		DY = threshold(vexRT[Ch2], 15);
		DT = threshold(vexRT[Ch1], 15);
		drive(DY, DT);
		//Pistons (toggle)
		if(vexRT[Btn7R]){
			pistons(!PISTON_POS);
			waitUntil(!vexRT[Btn7R]);
		}
		//Arms
		if(vexRT[Btn7L]){
			armsLocked = !armsLocked;
			waitUntil(!vexRT[Btn7L]);
		}
		if(armsLocked){
			arms(ARM_LOCK);
		} else {
			arms((vexRT[Btn6U] - vexRT[Btn6D]) * MAX_POWER);
		}
		//Lift
		lift((vexRT[Btn7U] - vexRT[Btn7D]) * MAX_POWER);
		//Intake
		intake((vexRT[Btn5U] - vexRT[Btn5D]) * MAX_POWER);
	}
}
