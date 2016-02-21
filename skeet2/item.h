//
//  item.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef item_h
#define item_h

#include <stdio.h>
#include "velocity.h"
#include "point.h"

class Item
{
   public:
   Item();
   Item(int x, int y) { location.setX(x); location.setY(y); }
   
   Point getLocation()     { return location;    }
   int   getOrientation()  { return orientation; }
   Velocity getVelocity()  { return velocity;    }
   
   void setLocation(       Point p) {    location = p; }
   void setOrientation(      int o) { orientation = o; }
   void setVelocity(    Velocity v) {    velocity = v; }

   void draw();
   void move(Point & newLocation);
   void turn(int newOrientation);
   
   private:
   //Member Data
   Velocity velocity;
   Point location;   // location of the polygon on the screen
   int orientation;  // the angle or orientation of the polygon
   
};

#endif /* item_h */
