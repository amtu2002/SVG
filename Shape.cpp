//
//  Shape.cpp
//  
//
//  Created by Amanda Tu on 2/22/21.
//

#include "Shape.h"
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

bool Rectangle::overlaps(const Shape& s) const
{
   return s.overlaps(*this);
}

bool Rectangle::overlaps(const Circle& r) const
{
    return r.overlaps(*this);
}
bool Rectangle::overlaps(const Rectangle& r) const
{
    if((position.x+width) <= r.position.x)
        return false;
    if((r.position.x+r.width) <= position.x )
        return false;
    if(position.y >= (r.position.y+r.height))
        return false;
    if(r.position.y >= (position.y +height))
        return false;
    //if(((r.position.y +r.height)>= position.y) && ((position.x+width) <= r.position.x) )
        //return false;
    //if(((r.position.y +r.height)>= position.y) && ((r.position.x+r.width) <= position.x))
        //return false;
   // if(((position.x-r.position.x)*(position.x-r.position.x) < (maxWidth*maxWidth)) && ((position.y-r.position.y)* (position.y-r.position.y) < (maxHeight*maxHeight)))
        //return true;
    //if(((position.y+height+width) <= (r.position.y)) || (position.y >= (r.position.y+width+height)))
        //return false;
    //if(((position.x+width+height) <= r.position.x) || (position.x) >= (position.x+width+height))
        //return false;
    return true;
    
}
bool Rectangle::fits_in(const Rectangle& r) const
{
    //if((position.x + width) < (r.position.x + r.width) && (position.x > r.position.x) && (position.y > r.position.y) && (position.y+height) < (r.position.y + r.height))
        //return true;
    if(((r.position.y <= position.y) && (r.position.y +r.height >= position.y))&&((r.position.x <= position.x) && (r.position.x +r.width >= position.x))&& ((r.position.y+r.height) >= position.y) && (r.position.x+r.width) >= (position.x+width) && (r.position.y+r.height) >= (position.y+height))
        return true;
    return false;
}
void Rectangle::draw(void) const
{
    cout << "<rect x=\"" << position.x<< "\" y=\"" << position.y << "\" width=\"" <<  width << "\" height=\"" << height <<"\"/>"<<endl;
}
Rectangle::~Rectangle(void)
{}
bool Circle::overlaps(const Shape& s) const
{
   return s.overlaps(*this);
}

bool Circle::overlaps(const Rectangle& r) const
{
    int xmin = min(max(center.x,r.position.x),r.position.x+r.width);
    int ymin = min(max(center.y,r.position.y),r.position.y+r.height);
    int distance = (xmin-center.x)*(xmin-center.x) + (ymin-center.y)*(ymin-center.y);
    if(distance < radius*radius)
        return true;
    return false;
}
bool Circle::overlaps(const Circle& c) const
{
    int distance = (center.x - c.center.x)*(center.x - c.center.x) + (center.y - c.center.y)*(center.y - c.center.y);
    int rdis = radius*radius + c.radius*c.radius;
    if(distance > rdis|| distance == rdis)
        return false;
    return true;
}
bool Circle::fits_in(const Rectangle& r) const
{
    //if(center.x+radius > r.position.x+r.width || center.x-radius < r.position.y+r.height || center.y+radius > r.position.x+r.width ||center.y+radius < r.position.y+r.height)
        //return false;
    if(((center.x < r.position.x+r.width) && (center.x > r.position.x))&&((center.y < r.position.y+r.height) && (center.y > r.position.y))&& (center.x+radius <=r.position.x+r.width) && (center.x-radius >=r.position.x) && (center.y+radius <= r.position.y+r.height) && (center.y-radius >= r.position.y))
        return true;
    return false;
    
}
void Circle::draw(void) const
{
    cout << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" <<  radius <<"\"/>"<<endl;
}
Circle::~Circle(void)
{}
