```cpp

#include<iostream>
#include<math.h>
#include"console.h"
#include"gtypes.h"
#include"gwindow.h"
using namespace std;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 800;
static const int BASE_Y = SCREEN_HEIGHT - SCREEN_HEIGHT * .35;
static const int BASE_LEFT_X = 170;
static const int BASE_RIGHT_X = SCREEN_WIDTH - 170;
static const double COS_60 = 0.5;
static const double SIN_60 = sqrt(3) * 0.5;


//return a Gpoint that forms an equilateral triangle 
GPoint thirdEquilateralPoint(GPoint bottomLeft, Gpoint otherPoint) {
double deltaX = otherPoint.x - bottomLeft.x;
double deltaY = otherPoint.y - bottomLeft.y;
double x = bottomLeft.x + (deltaX * COS_60 + deltaY * SIN_60);
double y = bottomLeft.y + (deltaY * COS_60 - deltaX * SIN_60);
Gpoint tip(x,y);
return tip;
}

GPoint pointBetween(GPoint p1,GPoint p2,double fraction)
{
 double x = p1.x + (p2.x - p1.x) * fraction;
 double y = p1.y + (p2.y - p1.y) * fraction;
return GPoint(x,y);

}

void drawSnowflake(GWindow& w,int level,GPoint start,GPoint end)
{
    if(level == 0) {
    w.drawLine(start, end);
    return;      
    }
    //recursive call
    //当没在最底层时，把需要的点算出来。总共三个
    GPoint a = pointBetween(start,end,1.0/3);
    GPoint b = pointBetween(start,end,2.0/3);
    GPoint t = thirdEquilateralPoint(a,b);
    
    //形成一个等边三角形后，我们就有四条边了。对这四条边，每条边都要调用drawSnowflake
    //写清楚start 和 end 就足够了
    //level 决定了这个雪花有几层
    drawSnowflake(w, level - 1,start, a);
    drawSnowflake(w, level - 1,a, t);
    drawSnowflake(w, level - 1,t, b);
    drawSnowflake(w, level - 1,b, end);

}

int main() {
GPoint top = thirdEquilateralPoint(bottomLeft,bottomRight);
drawSnowflake(w,7,bottomRight,bottomLeft);
drawSnowflake(w,7,bottomRight,top);
drawSnowflake(w,7,top,bottomLeft);
return 0;


}

```