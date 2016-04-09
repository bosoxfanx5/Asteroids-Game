 //
//  asteroid.h
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#ifndef asteroid_h
#define asteroid_h

#include <stdio.h>
#include "item.h"
#include "uiDraw.h"
#include <vector>

class Asteroid : public Item
{
   public:
   //Bullet constructor contains defaults for all needed values
   Asteroid() : Item (-100, 100) //Start location is at left edge.
   {
   }
   
   ~Asteroid() {};
   
   //Draw method lets the asteroids draw themselves on the screen
   //void draw() { drawRect(Item::getLocation(), 20, 20, Item::getOrientation()); }
   void draw()
   {
      switch (type)
      {
      case 1:
         drawSmallAsteroid(Item::getLocation(), Item::getOrientation());
         break;
      case 2:
         drawMediumAsteroid(Item::getLocation(), Item::getOrientation());
         break;
      case 3:
         drawLargeAsteroid(Item::getLocation(), Item::getOrientation());
         break;
      default:
         return;
      }
   }
   
   //We're calling these from their parent class
   Point    getLocation()  { return Item::getLocation();    }
   int   getOrientation()  { return Item::getOrientation(); }
   Velocity getVelocity()  { return Item::getVelocity();    }
   
   Point origin;
   Point destination;
   int pointValue = 1;
   
   void setLocation(       Point p) { Item::setLocation(p);    }
   void setOrientation(      int o) { Item::setOrientation(o); }
   void setVelocity(    Velocity v) { Item::setVelocity(v);    }
   
   void move() { Item::move();    }
   void explode(std::vector <Asteroid> & asteroidVector, Point p)
   {
      switch (type)
      {
         case 1:
            break;
         case 2:
            //2->2x 1]
            launch(asteroidVector, 1, p);
            launch(asteroidVector, 1, p);
            break;
         case 3:
            //3->2x 2 & 1x 1
            launch(asteroidVector, 1, p);
            launch(asteroidVector, 2, p);
            launch(asteroidVector, 2, p);
            break;
         default:
            return;
      }
   }
   
   int type = 0; //1 = small, 2 = medium, 3 = large
   
   static void launch(std::vector <Asteroid> & asteroidVector, int size, Point pin = new Point(0,0));
   
};
//
//class Pebble : public Asteroid
//{
//   Pebble() : Asteroid() {};
//   void split();
//};
//
//class Rock : public Asteroid
//{
//   Rock() : Asteroid() {};
//   void split();
//};
//
//class Boulder : public Asteroid
//{
//   Boulder() : Asteroid() {};
//   void split();
//};
//
#endif /* asteroid_h */
