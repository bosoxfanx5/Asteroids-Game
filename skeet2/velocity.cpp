//
//  velocity.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "velocity.h"
#include <math.h>

void Velocity :: convertSlope()
{
    int x = hypotenuse * cos(this->angle * (M_PI / 180));
    int y = hypotenuse * sin(this->angle * (M_PI / 180));
    
    this->slope.setX(x);
    this->slope.setY(y);

}