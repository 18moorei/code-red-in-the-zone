#ifndef MOTION_H_

#define MOTION_H_

//Power Values
#define MAX_POWER 127
#define ARM_LOCK 18
#define MOGO_LOCK 25

//Positioning Simplification
#define GYRO_SIMPLE (SensorValue[gyro] % 3600 / 10)

//Controller Mirroring
#define PAIRED_CH1 (vexRT[Ch1] + vexRT[Ch1Xmtr2])
#define PAIRED_CH2 (vexRT[Ch2] + vexRT[Ch2Xmtr2])
#define PAIRED_CH3 (vexRT[Ch3] + vexRT[Ch3Xmtr2])
#define PAIRED_CH4 (vexRT[Ch4] + vexRT[Ch4Xmtr2])

#define PAIRED_BTN5U (vexRT[Btn5U] || vexRT[Btn5UXmtr2])
#define PAIRED_BTN5D (vexRT[Btn5D] || vexRT[Btn5DXmtr2])
#define PAIRED_BTN6U (vexRT[Btn6U] || vexRT[Btn6UXmtr2])
#define PAIRED_BTN6D (vexRT[Btn6D] || vexRT[Btn6DXmtr2])

#define PAIRED_BTN7U (vexRT[Btn7U] || vexRT[Btn7UXmtr2])
#define PAIRED_BTN7L (vexRT[Btn7L] || vexRT[Btn7LXmtr2])
#define PAIRED_BTN7R (vexRT[Btn7R] || vexRT[Btn7RXmtr2])
#define PAIRED_BTN7D (vexRT[Btn7D] || vexRT[Btn7DXmtr2])

#define PAIRED_BTN8U (vexRT[Btn8U] || vexRT[Btn8UXmtr2])
#define PAIRED_BTN8L (vexRT[Btn8L] || vexRT[Btn8LXmtr2])
#define PAIRED_BTN8R (vexRT[Btn8R] || vexRT[Btn8RXmtr2])
#define PAIRED_BTN8D (vexRT[Btn8D] || vexRT[Btn8DXmtr2])

#define PAIRED_ACCELX (vexRT[AccelX] > vexRT[AccelXXmtr2] ? vexRT[AccelX] : vexRT[AccelXXmtr2])
#define PAIRED_ACCELY (vexRT[AccelY] > vexRT[AccelYXmtr2] ? vexRT[AccelY] : vexRT[AccelYXmtr2])
#define PAIRED_ACCELZ (vexRT[AccelZ] > vexRT[AccelZXmtr2] ? vexRT[AccelZ] : vexRT[AccelZXmtr2])

#endif
