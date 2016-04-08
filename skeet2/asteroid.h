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
   
   //Draw method lets the asteroids draw themselves on the screen
   //void draw() { drawRect(Item::getLocation(), 20, 20, Item::getOrientation()); }
   void draw() { drawLargeAsteroid(Item::getLocation(), Item::getOrientation()); }
   
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
   void explode();
   virtual void split(std::vector <Asteroid*> & asteroidVector) = 0;
   
   static void launch(std::vector <Asteroid*> & asteroidVector, int size);
   
};

class Pebble : public Asteroid
{
public:
   Pebble() : Asteroid() {};
   void split(std::vector <Asteroid*> & asteroidVector) {};
};

class Rock : public Asteroid
{
public:
   Rock() : Asteroid() {};
   void split(std::vector <Asteroid*> & asteroidVector) {};
};

class Boulder : public Asteroid
{
public:
   Boulder() : Asteroid() {};
   virtual void split(std::vector <Asteroid*> & asteroidVector);
   //void (Boulder::*split)(std::vector <Asteroid> & asteroidVector) const = NULL;
};

#endif /* asteroid_h */
