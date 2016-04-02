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
   int degrees = 2;
   
   //if the tick count is less than or equal to zero
   if(ticks >= 0) ticks++;    //subract one from the tick count
   else           ticks = 1; //otherwise, set the tick count to -1
   
   //if the tick count is less than -3
   if(ticks < -5) degrees = 3; //set the degrees of rotation to -3
   
   //if the rifle orientation is less than the max
   //if (this->getOrientation() < shipAngleMax)
      Item::setOrientation(Item::getOrientation() + degrees); //add degrees (-)
   //else
      //Item::setOrientation(shipAngleMax); //otherwise, reset to max
}

void Ship :: turnRight()
{
   //set degrees of rotation
   int degrees = -2;
   
   //if the tick count is less than or equal to zero
   if(ticks <= 0) ticks--;    //subract one from the tick count
   else           ticks = -1; //otherwise, set the tick count to -1
   
   //if the tick count is less than -3
   if(ticks < -5) degrees = -3; //set the degrees of rotation to -3
   
   //if the rifle orientation is less than the max
   //if (this->getOrientation() > shipAngleMin)
      Item::setOrientation(Item::getOrientation() + degrees); //add degrees (-)
   //else
      //Item::setOrientation(shipAngleMin); //otherwise, reset to max
}

void Ship :: thrust()
{
   //Item::setVelocity(10);
   velocity.increaseSpeed(.1);
   
   int y = velocity.getHypotenuse() * sin(this->getOrientation() * (M_PI / 180));
   int x = velocity.getHypotenuse() * cos(this->getOrientation() * (M_PI / 180));
   
   Point p(x,y);
   
   velocity.setSlope(p);
}

void Ship :: fireShip(std::vector <Bullet> & bulletVector)
{
    //If we have less than 5 bullets in the vector
    if (bulletVector.size() < 5)
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