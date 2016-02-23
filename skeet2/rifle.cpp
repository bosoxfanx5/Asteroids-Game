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
    Bullet b;
    b.setAngle(this->getOrientation());
    bulletVector.push_back(b);
    
}