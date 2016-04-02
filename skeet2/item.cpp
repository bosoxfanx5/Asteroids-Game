//
//  item.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "item.h"
#include "point.h"

void Item::move(Point & newLocation)
{
   location.setX(newLocation.getX());
   location.setY(newLocation.getY());
}

void Item::move()
{
   Velocity     v = this->getVelocity();
   Point    slope = v.getSlope();
   Point location = this->getLocation();

   location.addX(slope.getX());
   location.addY(slope.getY());
   
   this->orientation += velocity.getRotationalVelocity();

   this->setLocation(location);
}

void Item::turn(int newOrientation)
{
   orientation = newOrientation;
}