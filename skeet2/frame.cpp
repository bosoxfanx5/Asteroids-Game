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

//void Frame::draw(void (*callBack)(const Frame *))
//{
//   // setup the callbacks
//   this->p = p;
//   this->callBack = callBack;
//
//   glutMainLoop();
//
//   return;
//}