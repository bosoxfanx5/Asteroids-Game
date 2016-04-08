 //
//  asteroid.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "asteroid.h"
#include "math.h"

void Asteroid::launch(std::vector <Asteroid> & asteroidVector, int size)
{
   Asteroid* pAsteroid;
   
   //Asteroid myAsteroid; //maybe this needs to be a pointer?
   switch (size)
   {
      case 0:
      {
         Pebble a;
         pAsteroid = &a;
         break;
      }
      case 1:
      {
         Rock a;
         pAsteroid = &a;
         break;
      }
      case 2:
      {
         Boulder a;
         pAsteroid = &a;
         break;
      }
      default:
         return;
   }
   
   //Asteroid* pAsteroid = &a;
   
   float slope;
   
   Point p;
   Velocity v;
   int endY;
   do
   {
      endY = 0;
      double hSpeed = random( -4, 4);
      double vSpeed = random( -4, 4);
      
      p.setX(hSpeed);
      p.setY(vSpeed);
      
      slope = vSpeed/hSpeed;
      
      //generate origin - far left
      //myAsteroid.origin.setX(-200);
      pAsteroid->origin.setX(-200);
      
      //If slope is positive, start on the bottom, else start on the top
      if(slope > 0)
         pAsteroid->origin.setY(random(-200,0)); //start on bottom
      else
         pAsteroid->origin.setY(random(0,200)); //start on top
      
      //check bounds on the destination
      int frames = 400 / hSpeed; //frames it will take to go across screen
      endY = pAsteroid->origin.getY() + (vSpeed * frames); // destination
      
   } while(endY > 200 || endY < -200 || pAsteroid->origin.getY() == endY); //Repeat until destionation is in range
   
   //set the asteroid location to it's origin
   pAsteroid->setLocation(pAsteroid->origin);
   
   //give velocity the slope
   v.setSlope(p);
   v.setRotationalVelocity(10);
   
   //impart velocity to asteroid
   pAsteroid->setVelocity(v);
   
   //push asteroid onto stack
   asteroidVector.push_back(*pAsteroid);
}

void Boulder::split(std::vector <Asteroid> & asteroidVector)
{
   Asteroid::launch(asteroidVector, 1);
   Asteroid::launch(asteroidVector, 1);
   Asteroid::launch(asteroidVector, 0);
   //asteroidVector.push_back(r1);
   //asteroidVector.push_back(r2);
}


//*/