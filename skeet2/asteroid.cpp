//
//  asteroid.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "asteroid.h"
#include "math.h"

void Asteroid::launch(std::vector <Asteroid> & asteroidVector)
{
   
   Asteroid myAsteroid;
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
      myAsteroid.origin.setX(-200);
      
      //If slope is positive, start on the bottom, else start on the top
      if(slope > 0)
         myAsteroid.origin.setY(random(-200,0)); //start on bottom
      else
         myAsteroid.origin.setY(random(0,200)); //start on top
      
      //check bounds on the destination
      int frames = 400 / hSpeed; //frames it will take to go across screen
      endY = myAsteroid.origin.getY() + (vSpeed * frames); // destination
      
   } while(endY > 200 || endY < -200 || myAsteroid.origin.getY() == endY); //Repeat until destionation is in range
   
   //set the asteroid location to it's origin
   myAsteroid.setLocation(myAsteroid.origin);
   
   //give velocity the slope
   v.setSlope(p);
   
   //impart velocity to asteroid
   myAsteroid.setVelocity(v);
   
   //push asteroid onto stack
   asteroidVector.push_back(myAsteroid);
}
//*/