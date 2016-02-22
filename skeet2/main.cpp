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
//void callBack(const Interface *pUI, void * vp)
void callBack(const Interface *pUI, void * p)
{
/*
  ___  __   __            __                  ___  __
 |__  |__) /  \  |\/|    /  `  /\  |    |    |__  |__)
 |    |  \ \__/  |  |    \__, /--\ |___ |___ |___ |  \
 
*/
   //Ball * pBall = (Ball *)p;  // cast the void pointer into a known type
   //std::vector<Ball> ballVector = *(std::vector<Ball> *)vp;
   //std::vector<Ball> ballVector = *(std::vector<Ball> *)vp;
   
   
   Frame * pFrame = (Frame *)p;  // cast the void pointer into a known type
   
   // rotate the rifle
   if (pUI->isRight()) pFrame->rifle.turnRight();
   if (pUI->isLeft())  pFrame->rifle.turnLeft();
   
   pFrame->rifle.draw();
   
   //Offset for testing...
   int offset = 0; //to sepearate objects
   int vectorOffset = 0;
   
   //Iterate through vector that was passed in...
//   for (std::vector<Ball>::iterator it  = ballVector.begin();
//                                    it != ballVector.end();
//                                  ++it)
//   {
//      //Ball * b = &(*it); //This works in place of it.
//      //Ball * b = &ballVector[vectorOffset];
//      //Ball * b = &ballVector[vectorOffset];
//      
//      
//      b->pt.addX(offset);
//      b->pt.addY(offset);
//      
//      // move the polygon
//      //if (pUI->isRight()) pUI->rifle.turnRight();
//      //if (pUI->isLeft())  pUI->rifle.turnLeft();
//      
//      if (pUI->isRight()) b->pt.addX( 1);
//      if (pUI->isLeft())  b->pt.addX(-1);
//      if (pUI->isUp())    b->pt.addY( 1);
//      if (pUI->isDown())  b->pt.addY(-1);
//   
//      // rotate constantly
//      b->rotation++;
//   
//      // draw
//      drawPolygon(b->rotation, //position//
//                  20,           // radius //
//                  b->sides,    //segments//
//                  b->rotation);//rotation//
//      
//      ballVector[vectorOffset] = *b;
//      
//      offset +=20;
//      vectorOffset++;
//   }
   
/*
 ___  _ ____ ____ ____ ___
 |  \ | |__/ |___ |     |
 |__/ | |  \ |___ |___  |

*/
   
   //Rifle r;
   //r.draw();
   
   //pUI->drawRifle();
   
   Velocity v(10);
   
   Bullet b;
   b.setVelocity(v);
   b.draw();
   
   for (int i = 0; i < 10; i++)
   {
      Point bulletLocation = b.getLocation();
      bulletLocation.addX(-10);
      bulletLocation.addY(10);
      b.setLocation(bulletLocation);
      b.draw();
   }
   
   //Pigeon p;
   //p.draw();
   
   Banner banner;
   banner.draw();
   
   
   //drawRect(r.getLocation(), r.width, r.length, r.getOrientation());
   //drawPolygon(r.pt, 5, 4, r.rotation+=10);
   
/*
   ____ ____ _ ____ _ _  _ ____ _
   |  | |__/ | | __ | |\ | |__| |
   |__| |  \ | |__] | | \| |  | |___

*/
//   // move the polygon
//   if (pUI->isRight())
//      pBall->pt.addX(1);
//   if (pUI->isLeft())
//      pBall->pt.addX(-1);
//   if (pUI->isUp())
//      pBall->pt.addY(1);
//   if (pUI->isDown())
//      pBall->pt.addY(-1);
//   
//   // use the space bar to change the number of sides.
//   if (pUI->isSpace())
//      pBall->sides++;
//   if (pBall->sides == 12)
//      pBall->sides = 3;
//   
//   // rotate constantly
//   pBall->rotation++;
//   
//   // draw
//   drawPolygon(pBall->pt, /*position*/
//               20, /* radius */
//               pBall->sides /*segments*/,
//               pBall->rotation /*rotation*/);
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my ball type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Interface ui(argc, argv, "Test", Point(-200, 200), Point(200, -200));    // initialize OpenGL
   //Interface ui(argc, argv, "Test");    // initialize OpenGL
   
   Frame mainFrame;
   Ball ball2;                           // initialize the game state
   //Rifle rifle;
   
   int size = 2;
   std::vector<Ball> ballVector(size);
   //std::vector<Item> itemVector(size);
   
   //itemVector.push_back(rifle);
   
   //ui.run(callBack, &ball);             // set everything into action
   ui.run(callBack, &mainFrame);         // set everything into action
   
   return 0;
}