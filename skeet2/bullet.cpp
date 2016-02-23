//
//  bullet.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "bullet.h"

void Bullet::move()
{
   Velocity v = this->getVelocity();
   Point slope = v.getSlope();
   Point location = this->getLocation();
   
   location.addX(slope.getX());
   location.addY(slope.getY());
   
   this->setLocation(location);
}