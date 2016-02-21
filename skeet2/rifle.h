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

class Rifle : Item
{
   public:
     Rifle() : length(10), width(30), pt() { }
   
   // this is just for test purposes.  Don't make member variables public!
   Point pt;          // location of the polygon on the screen
   int sides;         // number of sides in the polygon.  Initially three
   int rotation;      // the angle or orientation of the polygon
   int length;
   int width;
};

#endif /* rifle_h */
