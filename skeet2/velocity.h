//
//  velocity.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef velocity_h
#define velocity_h

#include <stdio.h>
#include "point.h"

#endif /* velocity_h */

class Velocity
{
public:
   Velocity()      {hypotenuse = 0;}
   Velocity(int h) {hypotenuse = h;}
   void setSpeed(int s) {hypotenuse = s;}  //protected?
   
   private:
    Point slope;
    
    void setAngle(int a) {angle = a; convertSlope();}
    
   
    float hypotenuse = 0; //speed in pixels per frame
    float angle = 0;
   
    void convertSlope();
};