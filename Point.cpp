//
//  Point.cpp
//  
//
//  Created by Amanda Tu on 2/22/21.
//

#include "Point.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Point Point::operator +(const Point& rhs) const
{
    int nX = x + rhs.x;
    int nY = y + rhs.y;
    return Point(nX,nY);
}

Point Point:: operator -( const Point& rhs) const
{
    // can the points be negative?
    int nX = x - rhs.x;
    int nY = y - rhs.y;
    return Point(nX,nY);
}
std::ostream& operator <<(ostream& os, const Point& p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

std::istream& operator >>(istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}

