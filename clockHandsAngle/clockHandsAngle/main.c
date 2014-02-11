//
//  main.c
//  clockHandsAngle
//
//  Created by Michael Raimi on 1/22/14.
//  Copyright (c) 2014 Michael Raimi. All rights reserved.
//

#include <stdio.h>

#define MIN_HAND_PER_MIN  (6)
#define HOUR_HAND_PER_MIN  (.5)

void calcAngle(int hour, int min){
    printf("HOUR_HAND_PER_MIN:%f\n", (double) HOUR_HAND_PER_MIN);
    printf("MIN_HAND_PER_MIN:%f\n", (double) MIN_HAND_PER_MIN);

    
    double minPastTwelve = (hour*60+min)%(12*60);
    printf("min past twelve: %f\n", minPastTwelve);
    double minuteAngle = min*MIN_HAND_PER_MIN;
    printf("minutes hand:%f\n", minuteAngle);
    double hourAngle = ((double)minPastTwelve)*HOUR_HAND_PER_MIN;
   
    
    printf("hours hand:%f\n", hourAngle);
    double angle = (minuteAngle-hourAngle);
    
    while (angle>360) {
        angle -= 360;
    }
    
    
    
    if (angle<-180) {
        printf("Angle: %f\n",360+angle);
    } else if (angle < 0 && angle >= -180){
        printf("Angle: %f\n",-1*angle);
    } else if (angle>180){
        printf("Angle: %f\n", 360-angle);
    } else {
        printf("Angle: %f\n", angle);
    }
}

int main(int argc, const char * argv[])
{

  calcAngle(11, 59);
    return 0;
}

