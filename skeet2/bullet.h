//
//  bullet.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef bullet_h
#define bullet_h

#include <stdio.h>
#include "item.h"
#include "uiDraw.h"

class Bullet : Item
{
public:
   //Bullet constructor contains defaults for all needed values
   Bullet() : Item (200, -200) //Start location is center of gun.
   {
       velocity.setSpeed(10);
   }
   
   //Draw method lets the bullets draw themselves on the screen
   void draw() { drawDot(Item::getLocation()); }
   
   //We're calling these from their parent class
   Point    getLocation()  { return Item::getLocation();    }
   int   getOrientation()  { return Item::getOrientation(); }
   Velocity getVelocity()  { return Item::getVelocity();    }
   
   
   void setLocation(       Point p) { Item::setLocation(p);    }
   void setOrientation(      int o) { Item::setOrientation(o); }
   void setVelocity(    Velocity v) { Item::setVelocity(v);    }
   void setAngle(           int a)  { Item:setAngle(a);        }
   
   void move();
};

#endif /* bullet_h */
