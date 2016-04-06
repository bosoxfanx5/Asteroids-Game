//
//  ship.cpp
//  asteroids
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "ship.h"
void Ship :: turnLeft()
{
   //set degrees of rotation
   int degrees = 10;
   Item::setOrientation(Item::getOrientation() + degrees);
}

void Ship :: turnRight()
{
   //set degrees of rotation
   int degrees = -10;
   Item::setOrientation(Item::getOrientation() + degrees);
}

void Ship :: thrust()
{
   Velocity push(.2, 0.0);
   push.setAngle(this->getOrientation());
   Point p((velocity.getSlope().getX() + push.getSlope().getX()),
            velocity.getSlope().getY() + push.getSlope().getY());
   velocity.setSpeed(sqrt(pow(p.getX(),2) + pow(p.getY(),2)));
   velocity.setSlope(p);
   drawThrust = true;
}

void Ship :: fireShip(std::vector <Bullet> & bulletVector)
{
    //If we have less than 5 bullets in the vector
    if (bulletVector.size() < 500)
    {
       //create a new bullet
       Bullet b;
       
       Point l = this->getLocation();
       b.setLocation(l);

       b.setOrientation(0);
       
       Velocity v;
       v.setSpeed(10);
       v.setAngle(this->getOrientation());
       
       b.setVelocity(v);
       
       bulletVector.push_back(b);
    }
}