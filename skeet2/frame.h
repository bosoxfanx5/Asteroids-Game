//
//  frame.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef frame_h
#define frame_h

#include <stdio.h>
#include <vector>
#include "rifle.h"
#include "pigeon.h"
#include "bullet.h"
#include "banner.h"

//#define LINUX
#define MAC_XCODE
//#define WIN_VISUAL_STUDIO

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

class Frame
{
   public:
   Frame();
   
      //Member Data
      //Rifle rifle();
      std::vector<Rifle> rifleVector; // < 3
   
      //Pigeon pigeon;
      std::vector<Pigeon> pigeonVector; // < 1
   
      //Bullets
      std::vector<Bullet> bulletVector; // < 5
   
      //Banner
      Banner banner;
      int frameRate = 30;
      void draw();
      //void draw(void (*callBack)(const Frame *));
      void draw(void (*callBack)(const Frame *, void *), void *p);
      void detectCollisions();
   
   private:
      //Member Functions
      
   
      static void *p;                   // for client
      static void (*callBack)(const Frame *, void *);
      //static void (*callBack)(const Frame *);
};

#endif /* frame_h */