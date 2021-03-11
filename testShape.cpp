//
// testShape.cpp
//

#include "Shape.h"
#include <iostream>
using namespace std;

int main()
{
  Point center(10,30);
  const int radius = 50;
  Circle c(center,radius);
  c.draw();

  //Point llcorner = Point(50,70);
  //const int width = 25;
  //const int height = 80;
  Rectangle r1(Point(0,0),600,500);
  r1.draw();

  Rectangle r2(Point(25,350),50,50);
  r2.draw();

  Circle c1(Point(500,250),200);
  c1.draw();
  Circle c2(Point(0,0),10000);
  c2.draw();

  cout << boolalpha << r2.fits_in(r1) << endl;
  cout << boolalpha << c2.fits_in(r1) << endl;
  cout << boolalpha << c1.fits_in(r1) << endl;
}
