  /****************************************
 * UI TEST
 * Just a simple program to test the user
 * interface consisting of uiDraw and uiInteract
 ***************************************/

#include <vector>
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ship.h"
#include "bullet.h"
#include "asteroid.h"
#include "banner.h"
#include "frame.h"
#include "assert.h"
using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
/*
  ___  __   __            __                  ___  __
 |__  |__) /  \  |\/|    /  `  /\  |    |    |__  |__)
 |    |  \ \__/  |  |    \__, /--\ |___ |___ |___ |  \
 
*/
   
   Frame * pFrame = (Frame *)p;  // cast the void pointer into a known type
   pFrame->banner.draw();
   
   
   if (pFrame->gameOver)
      drawGameOver();
   
   
   // rotate and fire the ship
   //Ship 1
   if (pUI->isUp())    pFrame->shipVector[0].thrust();
   if (pUI->isRight()) pFrame->shipVector[0].turnRight();
   if (pUI->isLeft())  pFrame->shipVector[0].turnLeft();
   if (pUI->isSpace()) pFrame->shipVector[0].fireShip(pFrame->bulletVector);
   
   //Ship 2
   if (pUI->isF4()) pFrame->shipVector[1].thrust();
   if (pUI->isF1()) pFrame->shipVector[1].turnRight();
   if (pUI->isF3()) pFrame->shipVector[1].turnLeft();
   if (pUI->isF2()) pFrame->shipVector[1].fireShip(pFrame->bulletVector);
   
   
   //RIFLES
   int vectorOffset = 0;
   for (std::vector<Ship>::iterator it  = pFrame->shipVector.begin();
                                     it != pFrame->shipVector.end();
                                   ++it)
   {   //r is a pointer to a ship in the vector
      Ship * r = &pFrame->shipVector[vectorOffset];
      
      //Move the ship using it's own move method.
      r->move();
      
      Point shipLocation = r->getLocation();
//*/
      if (shipLocation.getX() < -400) shipLocation.setX( 400);
      if (shipLocation.getX() >  400) shipLocation.setX(-400);
      if (shipLocation.getY() < -300) shipLocation.setY( 300);
      if (shipLocation.getY() >  300) shipLocation.setY(-300);
//*/
      pFrame->shipVector[vectorOffset++].setLocation(shipLocation);
      
      //Draw the ship at it's current location
      r->draw();
      //vectorOffset++;
   }

   
   //BULLETS
   vectorOffset = 0;
   for (std::vector<Bullet>::iterator it  = pFrame->bulletVector.begin();
                                      it != pFrame->bulletVector.end();
                                    ++it)
    {   //b is a pointer to a bullet in the vector
        Bullet * b = &pFrame->bulletVector[vectorOffset];
       
        //Move the bullet using it's own move method.
        b->move();
       
        //Draw the bullet at it's current location
        b->draw();
       
        //If location has not changed on a bullet we want to know about it
        assert(                                   b->getLocation()
               == pFrame->bulletVector[vectorOffset].getLocation());
       
       
        Point bulletLocation = b->getLocation();
       
        if (bulletLocation.getX() < -400 || bulletLocation.getX() > 400 ||
            bulletLocation.getY() < -300 || bulletLocation.getY() > 300)
        {
           //delete asteroid
           pFrame->bulletVector.erase(it);
           break; //break out of the loop
        }
        else
        {
           pFrame->bulletVector[vectorOffset++].setLocation(bulletLocation);
        }
    }
   
   //ASTEROIDS
   vectorOffset = 0;
   if (pFrame->asteroidVector.size() < 1 )
   {
      Asteroid::launch(pFrame->asteroidVector, 3);
   }
   
   for (std::vector<Asteroid>::iterator it = pFrame->asteroidVector.begin();
        it != pFrame->asteroidVector.end();
        ++it)
   {
      //p is a pointer to a asteroid in the vector
      Asteroid * pig = &pFrame->asteroidVector[vectorOffset];
      
      //Move the asteroid using it's own move method.
      pig->move();
      
      //Draw the asteroid at it's current location
      pig->draw();
      
      //If location has not changed on a asteroid we want to know about it
      assert(                                   pig->getLocation()
               == pFrame->asteroidVector[vectorOffset].getLocation());
      
      Point asteroidLocation = pig->getLocation();
      
      //*/
      if (asteroidLocation.getX() < -400) asteroidLocation.setX( 400);
      if (asteroidLocation.getX() >  400) asteroidLocation.setX(-400);
      if (asteroidLocation.getY() < -300) asteroidLocation.setY( 300);
      if (asteroidLocation.getY() >  300) asteroidLocation.setY(-300);
      //*/
      
      pFrame->asteroidVector[vectorOffset++].setLocation(asteroidLocation);
   }
   
   pFrame->detectCollisions();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my ball type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Test", Point(-400, 300), Point(400, -300));    // initialize OpenGL
   
   Frame mainFrame;
   
   ui.run(callBack, &mainFrame);         // set everything into action
   
   return 0;
}