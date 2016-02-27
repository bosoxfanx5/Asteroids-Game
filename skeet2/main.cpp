/****************************************
 * UI TEST
 * Just a simple program to test the user
 * interface consisting of uiDraw and uiInteract
 ***************************************/

#include <vector>
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "rifle.h"
#include "bullet.h"
#include "pigeon.h"
#include "banner.h"
#include "frame.h"
#include "assert.h"
using namespace std;

/************************************
 * Test structure to capture the ball
 * that I will move around the screen
 ***********************************/
class Ball
{
public:
   Ball() : sides(3), rotation(0), pt() { }
   
   // this is just for test purposes.  Don't make member variables public!
   Point pt;          // location of the polygon on the screen
   int sides;         // number of sides in the polygon.  Initially three
   int rotation;      // the angle or orientation of the polygon
};

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
   
   // rotate and fire the rifle
   //Rifle 1
   if (pUI->isRight()) pFrame->rifleVector[0].turnRight();
   if (pUI->isLeft())  pFrame->rifleVector[0].turnLeft();
   if (pUI->isSpace()) pFrame->rifleVector[0].fireRifle(pFrame->bulletVector);
   
   //Rifle 2
   if (pUI->isF1()) pFrame->rifleVector[1].turnRight();
   if (pUI->isF3()) pFrame->rifleVector[1].turnLeft();
   if (pUI->isF2()) pFrame->rifleVector[1].fireRifle(pFrame->bulletVector);
   
   
   //RIFLES
   int vectorOffset = 0;
   for (std::vector<Rifle>::iterator it  = pFrame->rifleVector.begin();
                                     it != pFrame->rifleVector.end();
                                   ++it)
   {   //r is a pointer to a rifle in the vector
      Rifle * r = &pFrame->rifleVector[vectorOffset];
      
      //Draw the rifle at it's current location
      r->draw();
      vectorOffset++;
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
       
        if (bulletLocation.getX() < -200 || bulletLocation.getX() > 200 ||
            bulletLocation.getY() < -200 || bulletLocation.getY() > 200)
        {
           //delete pigeon
           pFrame->bulletVector.erase(it);
           break; //break out of the loop
        }
        else
        {
           pFrame->bulletVector[vectorOffset++].setLocation(bulletLocation);
        }
    }
   
   //PIGEONS
   vectorOffset = 0;
   if (pFrame->pigeonVector.size() < 1 )
   {
      Pigeon::launch(pFrame->pigeonVector);
   }
   
   for (std::vector<Pigeon>::iterator it = pFrame->pigeonVector.begin();
        it != pFrame->pigeonVector.end();
        ++it)
   {
      //p is a pointer to a pigeon in the vector
      Pigeon * pig = &pFrame->pigeonVector[vectorOffset];
      
      //Move the pigeon using it's own move method.
      pig->move();
      
      //Draw the pigeon at it's current location
      pig->draw();
      
      //If location has not changed on a pigeon we want to know about it
      assert(                                   pig->getLocation()
               == pFrame->pigeonVector[vectorOffset].getLocation());
      
      
      Point pigeonLocation = pig->getLocation();
      
      if (pigeonLocation.getX() < -200 || pigeonLocation.getX() > 210 ||
          pigeonLocation.getY() < -200 || pigeonLocation.getY() > 210)
      {
         //Increment the counter on missed pigeons...
         pFrame->banner.incrementL();
         
         //delete pigeon
         pFrame->pigeonVector.erase(it);
         break; //break out of the loop
      }
      else
      {
         pFrame->pigeonVector[vectorOffset++].setLocation(pigeonLocation);
      }
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
   Interface ui(argc, argv, "Test", Point(-200, 200), Point(200, -200));    // initialize OpenGL
   
   Frame mainFrame;
   Ball ball2;                           // initialize the game state
   
   int size = 2;
   std::vector<Ball> ballVector(size);
   
   ui.run(callBack, &mainFrame);         // set everything into action
   
   return 0;
}