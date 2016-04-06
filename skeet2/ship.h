 //
//  ship.h
//  asteroids
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 POS Software Group, LTD. All rights reserved.
//

#ifndef ship_h
#define ship_h

#include <stdio.h>
#include "item.h"
#include "uiDraw.h"
#include <vector>
#include "bullet.h"
class Ship : Item
{
public:
   //Ship constructor contains defaults for all needed values
   Ship(int l = 60, int w = 10, int o = 0) : Item (0, 0)
   {
      setOrientation(o);
      width  = w;
      length = l;
      
      float slope;
      
      Point p;
      Velocity v;
      
      p.setX(0);
      p.setY(0);
      
      slope = 0;
      
      //give velocity the slope
      v.setSlope(p);
      v.setRotationalVelocity(0);
      
      //impart velocity to asteroid
      this->setVelocity(v);
      
      //push ship onto stack
      //shipVector.push_back(myAsteroid);
   }
   
   //Draw method lets the ship draw itself on the screen
   void draw() { drawShip(Item::getLocation(),
                          Item::getOrientation() - 90 , drawThrust); drawThrust = false; }
   
   //We're calling these from their parent class
   //Getters and Setters
   Point    getLocation()  { return Item::getLocation();    }
   int   getOrientation()  { return Item::getOrientation(); }
   Velocity getVelocity()  { return Item::getVelocity();    }
   
   void setOrientation(int o) { Item::setOrientation(o);       }
   void turnRight();
   void turnLeft();
   void thrust();
   void fireShip(std::vector <Bullet> & bulletVector);
   void setMinMax(int min, int max) {shipAngleMin = min; shipAngleMax = max;}
   void setLocation(int x, int y) {Item::setLocation(Point(x,y));}
   void setLocation(Point p) {Item::setLocation(p);}
   
   int length;
   int  width;
   bool drawThrust = false;
   
   int shipAngleMax = 180;
   int shipAngleMin = 90;
   
   int ticks;

   void move() { Item::move(); }
};

#endif /* ship_h */
