//
//  pigeon.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef pigeon_h
#define pigeon_h

#include <stdio.h>
#include "item.h"
#include "uiDraw.h"
#include <vector>

class Pigeon : Item
{
   public:
   //Bullet constructor contains defaults for all needed values
   Pigeon() : Item (-100, 100) //Start location is at left edge.
   {
   }
   
   //Draw method lets the pigeons draw themselves on the screen
   void draw() { drawCircle(Item::getLocation(), 20); }
   
   //We're calling these from their parent class
   Point    getLocation()  { return Item::getLocation();    }
   int   getOrientation()  { return Item::getOrientation(); }
   Velocity getVelocity()  { return Item::getVelocity();    }
   
   Point origin;
   Point destination;
   int pointValue = 1;
   
   void setLocation(       Point p) { Item::setLocation(p);    }
   void setOrientation(      int o) { Item::setOrientation(o); }
   void setVelocity(    Velocity v) { Item::setVelocity(v);    }
   
   void move() { Item::move();    }
   static void launch(std::vector <Pigeon> & pigeonVector);
   
};

#endif /* pigeon_h */
