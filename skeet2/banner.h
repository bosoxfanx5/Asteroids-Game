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
   Banner() : leftChar('0'), rightChar('0') {};
   
   //Draw Methods
   void draw()               {drawDigit(Point( 180, 180), rightChar);
                              drawDigit(Point(-180, 180), leftChar);}
   
   void draw(char l, char r) { leftChar  = l;
                               rightChar = r;
      
                              drawDigit(Point( 180, 180), rightChar);
                              drawDigit(Point(-180, 180), leftChar);}
   
   
   char  leftChar;
   char rightChar;
   
};

#endif /* banner_h */
