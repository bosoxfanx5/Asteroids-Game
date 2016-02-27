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
   Rifle r1;
   Rifle r2;
   r2.setMinMax(0, 90);
   r2.setLocation(-200, -200);
   
   rifleVector.push_back(r1);
   rifleVector.push_back(r2);
}

void Frame::detectCollisions()
{
   for (std::vector<Bullet>::iterator bit  = bulletVector.begin();
        bit != bulletVector.end() &&
               pigeonVector.size() != 0 &&
               bulletVector.size() != 0;
                                    ++bit)
      
   {
      for (std::vector<Pigeon>::iterator pit  = pigeonVector.begin();
           pit != pigeonVector.end() &&
                  pigeonVector.size() != 0 &&
                  bulletVector.size() != 0;
                                       ++pit)
      {
         int x1 = bit->getLocation().getX();
         int x2 = pit->getLocation().getX();
         int y1 = bit->getLocation().getY();
         int y2 = pit->getLocation().getY();
         
         std::cerr << "Distance: " << pow((pow((x2-x1), 2) +
                      pow((y2-y1), 2)), 0.5) << std::endl;
         
         if (pow((pow((x2-x1), 2) +
                  pow((y2-y1), 2)), 0.5) < 20)
         {
            banner.incrementR();
         
            pigeonVector.erase(pit);
            bulletVector.erase(bit);
            break;
         }
      }
      
   }
}