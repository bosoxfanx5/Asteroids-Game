  //
//  banner.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef banner_h
#define banner_h

#include <stdio.h>
#include "item.h"
#include "uiDraw.h"

class Banner
{
   public:
   Banner() : l(0), r(0) {};
   
   //Draw Methods
   void draw();
   
   void update( int lin,  int rin) { l = lin + 48; r = rin + 48;}
   
   void incrementL() { l++; }
   void incrementR() { r++; }
   
   
private:
   int l;
   int r;
   int  mostSignificantBit(int a);
   int leastSignificantBit(int a);
};

#endif /* banner_h */
