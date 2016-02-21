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
   Banner() {};
   void draw() {drawDigit(Point( 180, 180), '5');
                drawDigit(Point(-180, 180), '5');}
   
};

#endif /* banner_h */
