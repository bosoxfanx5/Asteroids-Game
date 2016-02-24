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
    if (this->getOrientation() < rifleAngleMax)
       Item::setOrientation(Item::getOrientation()+1);

}

void Rifle :: turnRight()
{
    if (this->getOrientation() > rifleAngleMin)
       Item::setOrientation(Item::getOrientation()-1);

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