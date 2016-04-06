 //
//  rifle.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef rifle_h
#define rifle_h

#include <stdio.h>
#include "item.h"
#include "uiDraw.h"
#include <vector>
#include "bullet.h"
class Rifle : Item
{
public:
   //Rifle constructor contains defaults for all needed values
   Rifle(int l = 60, int w = 10, int o = 135) : Item (200, -200)
   {
      setOrientation(o);
      width  = w;
      length = l;
   }
   
   //Draw method lets the rifle draw itself on the screen
   void draw() { drawRect(Item::getLocation(), length, width,
                          Item::getOrientation()); }
   
   //We're calling these from their parent class
   //Getters and Setters
   int getOrientation()      { return Item::getOrientation(); }
   void setOrientation(int o) { Item::setOrientation(o);       }
   void turnRight();
   void turnLeft();
   void fireRifle(std::vector <Bullet> & bulletVector);
   void setMinMax(int min, int max) {rifleAngleMin = min; rifleAngleMax = max;}
   void setLocation(int x, int y) {Item::setLocation(Point(x,y));}
   
   int length;
   int  width;
   
   int rifleAngleMax = 180;
   int rifleAngleMin = 90;
   
   int ticks;
};

#endif /* rifle_h */
