 //
//  frame.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef Frame
#include "frame.h"
#endif // Frame

//#define LINUX
#define MAC_XCODE
//define WIN_VISUAL_STUDIO
//
#define LINUX
//#define MAC_XCODE
//#define WIN_VISUAL_STUDIO
//

#ifdef MAC_XCODE
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#endif // MAC_XCODE

#ifdef LINUX
//#include <GL/gl.h>    // Main OpenGL library
//#include <GL/glut.h>  // Second OpenGL library
#endif // LINUX

#ifdef WIN_VISUAL_STUDIO
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>           // OpenGL library we copied
#include <ctime>            // for ::Sleep();
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#endif // WIN_VISUAL_STUDIO

//Member Functions
void Frame::draw()
{
   return;
}

Frame::Frame()
{
   Ship r1;
   Ship r2;
   r2.setMinMax(0, 90);
   r2.setLocation(-200, -200);
   r2.setOrientation(45);
   
   shipVector.push_back(r1);
   //shipVector.push_back(r2);
}

void Frame::detectCollisions()
{
   if (bulletVector.size() != 0)
      true;
   
   bool break2 = false;
   
   //for every ship
   for (std::vector<Ship>::iterator bit = shipVector.begin();
        bit != shipVector.end() &&
        asteroidVector.size() != 0 &&
        shipVector.size() != 0;)
   {
      //for every asteroid
      for (std::vector<Asteroid>::iterator pit = asteroidVector.begin();
           pit != asteroidVector.end() &&
           asteroidVector.size() != 0 &&
           shipVector.size() != 0;)
      {
         int x1 = bit->getLocation().getX();
         int x2 = pit->getLocation().getX();
         int y1 = bit->getLocation().getY();
         int y2 = pit->getLocation().getY();
         //std::cerr << "Distance: " << pow((pow((x2-x1), 2) +
         // pow((y2-y1), 2)), 0.5) << std::endl;
         
         //if the bullet and the asteroid are in proximity
         if (pow((pow((x2-x1), 2) + pow((y2-y1), 2)), 0.5) < 20)
         {
            banner.incrementR();
            // Here are the changes
            gameOver = true;
            Point p = pit->getLocation();
            pit = asteroidVector.erase(pit);
            pit->explode(asteroidVector, p);
            bit =   shipVector.erase(bit);
            break2 = true;
            break;
         }
         //else
         //{
         pit++; // get rid of ++pit in for loop declaration.
         // same
         //}
         //changes stop here
      }
      if (break2)
      {
         break2 = false;
         continue;
      }
      else
         bit++;
   }
   
   int i = 0;
   
   //for every bullet
   for (std::vector<Bullet>::iterator bit = bulletVector.begin();
        bit != bulletVector.end() &&
        asteroidVector.size() != 0 &&
        bulletVector.size() != 0;)
   {
      i = 0;
      //for every asteroid
      for (std::vector<Asteroid>::iterator pit = asteroidVector.begin();
           pit != asteroidVector.end() &&
           asteroidVector.size() != 0 &&
           bulletVector.size() != 0;)
      {
         i++;
         int x1 = bit->getLocation().getX();
         int x2 = pit->getLocation().getX();
         int y1 = bit->getLocation().getY();
         int y2 = pit->getLocation().getY();
         //std::cerr << "Distance: " << pow((pow((x2-x1), 2) +
         // pow((y2-y1), 2)), 0.5) << std::endl;
         
         //if the bullet and the asteroid are in proximity
         if (pow((pow((x2-x1), 2) + pow((y2-y1), 2)), 0.5) < 20)
         {
            std::cerr << "Asteroid Hit: " << i << ":" << pit->type << " at (" << pit->getLocation().getX() << ", " << pit->getLocation().getY() << ")" <<std::endl;
            banner.incrementR();
            // Here are the changes
            //Point p = pit->getLocation();
            
            bit = bulletVector.erase(bit);
            
            Point p(pit->getLocation().getX(),pit->getLocation().getY());
            
            pit = asteroidVector.erase(pit);
            
            //asteroidVector.erase(pit);
            
            pit->explode(asteroidVector, p);
            
            
            break2 = true;
            //break;
            return;
         }
         //else
         //{
         pit++; // get rid of ++pit in for loop declaration.
         // same
         //}
         //changes stop here
      }
      if (break2)
      {
         break2 = false;
         continue;
      }
      else
         bit++;
   }
}