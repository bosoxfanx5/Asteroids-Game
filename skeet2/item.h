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
      //Member Data
      Velocity velocity;
      Point location;
      int orientation;
   
   private:
      //Member Functions
      void draw();
      void move(Point & newLocation);
      void turn(int newOrientation);
};

#endif /* item_h */
