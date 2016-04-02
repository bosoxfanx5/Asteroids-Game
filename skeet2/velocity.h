//
//  velocity.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef velocity_h
#define velocity_h

#include <stdio.h>
#include "point.h"

#endif /* velocity_h */

class Velocity
{
public:
   //Constructors
   Velocity()                    { hypotenuse = 0; rotationalVelocity = 0; }
   Velocity(int h)               { hypotenuse = h;                         }
   Velocity(int h, float r)      { hypotenuse = h; rotationalVelocity = r; }
   
   //Movement
   void setSpeed(int s)          { hypotenuse = s;                         }
   Point getSlope()              { return slope;                           }
   void setSlope(Point p)        { slope = p;                              }
   
   //Orienation and Rotation
   void setAngle(int a)          { angle = a; convertSlope();              }
   float getRotationalVelocity() { return rotationalVelocity;              }
   void  setRotationalVelocity(float r) { rotationalVelocity = r;          }
   void  increaseSpeed(float r)  { hypotenuse += r; convertSlope();        }
   float getHypotenuse() {return hypotenuse;}
   
private:
    //Movement
    Point slope;
   
    float hypotenuse = 0; //speed in pixels per frame
    float angle = 0;
   
    void convertSlope();
   
    //Rotation
    float rotationalVelocity;
};