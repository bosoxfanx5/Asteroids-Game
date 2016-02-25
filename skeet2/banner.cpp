//
//  banner.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "banner.h"
#include <vector>

void Banner::draw()
{
   //Draw Left Score
   int offset = 0;
   int temp = l;
   int count = 0;
   
   std::vector<int> digitVectorLeft;
   
   while (temp > 0)
   {
      digitVectorLeft.push_back(temp % 10);
      temp /= 10;
      count++;
   }
   
   for (;count > 0; count--)
   {
      char c = (char) (digitVectorLeft[count - 1] + 48);
      drawDigit(Point(-180 + offset++ * 12, 180), c);
   }

   //Draw Right Score
   offset = 0;
   temp = r;
   
   std::vector<int> digitVectorRight;
   
   while (temp > 0)
   {
      digitVectorRight.push_back(temp % 10);
      temp /= 10;
   }
   
   for (count = 0; count < digitVectorRight.size(); count++)
   {
      char c = (char) (digitVectorRight[count] + 48);
      drawDigit(Point(180 - offset++ * 12, 180), c);
   }
}

int Banner::mostSignificantBit(int a)
{
   int temp1 = a;
   int temp2 = temp1;
   int count = 0;
   
   // Counting the number of digits in the entered integer
   while (temp1 != 0)
   {
      temp2  = temp1;
      temp1 /= 10;
      count++;
   }
   
   return temp2;
}

int Banner::leastSignificantBit(int a)
{
   return a % 10;
}