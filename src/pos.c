typedef struct {
	int x;
	int y;
	int z;
	int r;
} Point;

Point current_pos;
Point bias;

void setHome(void) {
	current_pos.x = 0;
	current_pos.y = 0;
	current_pos.r = 0;
	SensorValue[gyro] = 0;
	SensorScale[gyro] = 260;
	SensorFullCount[gyro] = 3600;
	SensorValue[aclX] = 0;
	SensorValue[aclY] = 0;
	SensorValue[aclZ] = 0;
	wait1Msec(1000);
	bias.x = SensorValue[aclX] + 2;
	bias.y = SensorValue[aclY] + 2;
	bias.z = SensorValue[aclZ] + 2;
}
