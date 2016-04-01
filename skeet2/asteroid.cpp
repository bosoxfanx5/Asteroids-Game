/*//
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
   
   Pigeon myPigeon;
   float slope;
   
   Point p;
   Velocity v;
   int endY;
   do
   {
      endY = 0;
      double hSpeed = random( 3,6);
      double vSpeed = random(-4,4);
      
      p.setX(hSpeed);
      p.setY(vSpeed);
      
      slope = vSpeed/hSpeed;
      
      //generate origin - far left
      myPigeon.origin.setX(-200);
      
      //If slope is positive, start on the bottom, else start on the top
      if(slope > 0)
         myPigeon.origin.setY(random(-200,0)); //start on bottom
      else
         myPigeon.origin.setY(random(0,200)); //start on top
      
      //check bounds on the destination
      int frames = 400 / hSpeed; //frames it will take to go across screen
      endY = myPigeon.origin.getY() + (vSpeed * frames); // destination
      
   } while(endY > 200 || endY < -200 || myPigeon.origin.getY() == endY); //Repeat until destionation is in range
   
   //set the pigeon location to it's origin
   myPigeon.setLocation(myPigeon.origin);
   
   //give velocity the slope
   v.setSlope(p);
   
   //impart velocity to pigeon
   myPigeon.setVelocity(v);
   
   //push pigeon onto stack
   pigeonVector.push_back(myPigeon);
}
*/