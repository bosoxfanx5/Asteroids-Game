//
//  ship.h
//  asteroids
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 POS Software Group, LTD. All rights reserved.
//

#ifndef ship_h
#define ship_h

#include <stdio.h>
#include "item.h"
#include "uiDraw.h"
#include <vector>
#include "bullet.h"
class Ship : Item
{
public:
   //Ship constructor contains defaults for all needed values
   Ship(int l = 60, int w = 10, int o = 135) : Item (200, -200)
   {
      setOrientation(o);
      width  = w;
      length = l;
   }
   
   //Draw method lets the ship draw itself on the screen
   void draw() { drawRect(Item::getLocation(), length, width,
                          Item::getOrientation()); }
   
   //We're calling these from their parent class
   //Getters and Setters
   int getOrientation()      { return Item::getOrientation(); }
   void setOrientation(int o) { Item::setOrientation(o);       }
   void turnRight();
   void turnLeft();
   void fireShip(std::vector <Bullet> & bulletVector);
   void setMinMax(int min, int max) {shipAngleMin = min; shipAngleMax = max;}
   void setLocation(int x, int y) {Item::setLocation(Point(x,y));}
   
   int length;
   int  width;
   
   int shipAngleMax = 180;
   int shipAngleMin = 90;
   
   int ticks;
};

#endif /* ship_h */
