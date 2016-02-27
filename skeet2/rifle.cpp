//
//  rifle.cpp
//  skeet
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "rifle.h"
void Rifle :: turnLeft()
{
   //ticks = 0;
   // if (this->getOrientation() < rifleAngleMax)
   //    Item::setOrientation(Item::getOrientation()+1);
   
   //set degrees of rotation
   int degrees = 2;
   
   //if the tick count is less than or equal to zero
   if(ticks >= 0) ticks++;    //subract one from the tick count
   else           ticks = 1; //otherwise, set the tick count to -1
   
   //if the tick count is less than -3
   if(ticks < -5) degrees = 3; //set the degrees of rotation to -3
   
   //if the rifle orientation is less than the max
   if (this->getOrientation() < rifleAngleMax)
      Item::setOrientation(Item::getOrientation() + degrees); //add degrees (-)
   else
      Item::setOrientation(rifleAngleMax); //otherwise, reset to max
}

void Rifle :: turnRight()
{
    //if (this->getOrientation() > rifleAngleMin)
    //   Item::setOrientation(Item::getOrientation()-1);
   
   //set degrees of rotation
   int degrees = -2;
   
   //if the tick count is less than or equal to zero
   if(ticks <= 0) ticks--;    //subract one from the tick count
   else           ticks = -1; //otherwise, set the tick count to -1
   
   //if the tick count is less than -3
   if(ticks < -5) degrees = -3; //set the degrees of rotation to -3
   
   //if the rifle orientation is less than the max
   if (this->getOrientation() > rifleAngleMin)
      Item::setOrientation(Item::getOrientation() + degrees); //add degrees (-)
   else
      Item::setOrientation(rifleAngleMin); //otherwise, reset to max
}

void Rifle :: fireRifle(std::vector <Bullet> & bulletVector)
{
    //If we have less than 5 bullets in the vector
    if (bulletVector.size() < 5)
    {
       //create a new bullet
       Bullet b;
       
       Point l = this->getLocation();
       b.setLocation(l);
       
       //set the bullet's orientation to the angle of the rifle
       //b.setOrientation(this->getOrientation());
       b.setOrientation(0);
       
       Velocity v;
       v.setSpeed(10);
       v.setAngle(this->getOrientation());
       
       b.setVelocity(v);
       
       bulletVector.push_back(b);
    }
}