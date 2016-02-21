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

void Item::turn(int newOrientation)
{
   orientation = newOrientation;
}