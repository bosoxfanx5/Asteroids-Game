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
   
   Point slope;
   
   float hypotenuse = 0; //speed
   float angle = 0;
   
   void convertSlope();
};