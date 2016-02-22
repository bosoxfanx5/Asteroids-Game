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
   //Getters and Getters
    int getOrientation()      { return Item::getOrientation(); }
   void setOrientation(int o) { Item::setOrientation(o);       }
   void turnRight() {Item::setOrientation(Item::getOrientation()-1);}
   void turnLeft()  {Item::setOrientation(Item::getOrientation()+1);}
   
   int length;
   int  width;
};

#endif /* rifle_h */
