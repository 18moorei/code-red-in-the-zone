#include "user.h"

task usercontrol(){
	int DY, DT;
	bool armsLocked = false;
	while(true){
		//Driving
		DY = threshold(PAIRED_CH2, 15);
		DT = threshold(PAIRED_CH1, 15);
		drive(DY, DT);
		//Pistons (toggle)
		if(PAIRED_BTN7R){
			pistons(!PISTON_POS);
			waitUntil(!PAIRED_BTN7R);
		}
		//Arms
		if(PAIRED_BTN7L){
			armsLocked = !armsLocked;
			waitUntil(!PAIRED_BTN7L);
		}
		if(armsLocked){
			arms(ARM_LOCK);
		} else {
			arms((PAIRED_BTN6U - PAIRED_BTN6D) * MAX_POWER);
		}
		//Lift
		lift((PAIRED_BTN7U - PAIRED_BTN7D) * MAX_POWER);
		//Intake
		intake((PAIRED_BTN5U - PAIRED_BTN5D) * MAX_POWER);
	}
}
