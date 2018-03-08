typedef struct {
	int total;
	int max;
} Cones;

Cones current_cones;

task autopreloader(){
	bool preloader = SensorValue[armEncoder] > -1380;
	while(true){
		preloader = false;
	}
}
