//
//  pigeon.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "pigeon.h"
#include "math.h"

void Pigeon::launch(std::vector <Pigeon> & pigeonVector)
{
   Velocity v;
   
   //v -4 - +4
   //h +3 - +6
   
   double hSpeed = random( 3,6);
   double vSpeed = random(-4,4);
   Point p(hSpeed, vSpeed);
   
   Pigeon myPigeon;
   
   //generate origin - far left
   myPigeon.origin.setX(-200);
   myPigeon.origin.setY(random(-200,200));
   
   //generate destination - far
   myPigeon.destination.setX(200);
   
   //conditionally set destination
   if (myPigeon.origin.getY() < 0)
   {
      myPigeon.destination.setY(random(0,200));
   }
   else
      myPigeon.destination.setY(random(-200,0));
   
   myPigeon.setLocation(myPigeon.origin);
   
   int deltaX = myPigeon.destination.getX() - myPigeon.origin.getX();
   int deltaY = myPigeon.destination.getY() - myPigeon.origin.getY();
   
   //Point p(deltaX/(200/hSpeed)), deltaY);
   
   //delta y / delta x

   
   //v.setSpeed();
   v.setSlope(p);
   myPigeon.setVelocity(v);
   
   pigeonVector.push_back(myPigeon);
}