# Code Red In The Zone
VEX Robotics Team 5111A (Code Red) In The Zone Competition Program

## The Project

In main.c we have the motor setup, the includes for linking the other files, and the pre-autonomous tasks of resetting the sensors and pairing (slaving) motors.

motion.c and motion.h include some of the most important functions and defines. Here I included functions for setting motor powers across the whole program, and short ways to make the partner controller work the same as the master controller. I also included functions to abstract the different functions such as moving the arm and driving, this made programing autonomous much easier and if I ever had to change anything I only have to do it in one place.

user.c contains the user control portion of the program. I tried to keep everything clear and concise while also being nice and compact. There is an additional task that blinks a warning LED on the bot to remind us to push a reset button we included for the sensors, once we got the bot in position on the field.

auto.c is split into two tasks, one for driving and one for manipulation. By doing this, we can control the movement of the arm, cone intake, and mobile goal picker-upper while also waiting for the accelerometer to interrupt the driving portion. We then use this multitasking to place the cone on the picked up mobile goal as we drive back. These optimizations saved us 3 seconds in autonomous allowing us to finish everything in time in about 13 seconds.
