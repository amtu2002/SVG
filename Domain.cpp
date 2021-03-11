//
//  Domain.cpp
//  
//
//  Created by Amanda Tu on 2/24/21.
//
#include "Domain.h"
#include <stdio.h>
#include <vector>
using namespace std;
Domain::Domain(void)
{
    sizex = 600;
    sizey = 500;
}

Domain::~Domain(void)
{}

void Domain::addShape(const Shape* p)
{
    s.push_back(p);
}

void Domain::draw(void)
{
    Rectangle boarder(Point(0,0),600,500);
    bool fits = true;
    bool overlap = false;
    for(unsigned i = 0; i< s.size();i++)
    {
        if(!s[i]->fits_in(boarder))
            fits = false;
        //cout <<"fits: "<< boolalpha << fits <<endl;
        for(unsigned j = i+1; j < s.size();j++)
        {
            if(s[i]->overlaps(*s[j]))
                overlap = true;
            //cout << "overlap: " <<boolalpha << overlap <<endl;
        }
    }
    cout <<"<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>"<< endl;
    cout << "<svg width=\"700\" height=\"600\""<< endl;
    cout << "xmlns=\"http://www.w3.org/2000/svg\">"<< endl;
    cout << "<g transform=\"matrix(1,0,0,-1,50,550)\""<< endl;
    cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">"<< endl;
    cout <<"<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl;
    
    for(unsigned i = 0; i < s.size();i++)
    {
        const Rectangle* isRect = dynamic_cast<const Rectangle*>(s[i]);
        const Circle* isC = dynamic_cast<const Circle*>(s[i]);
        if(isRect)
            cout <<"<rect x=\"" << isRect->position.x << "\" y=\"" << isRect->position.y << "\" width=\"" <<  isRect->width << "\" height=\"" << isRect->height <<"\"/>" << endl;
        if(isC)
            cout << "<circle cx=\"" << isC->center.x << "\" cy=\"" << isC->center.y << "\" r=\"" <<  isC->radius <<"\"/>"<<endl;
    }
    cout << "</g>"<<endl;
    cout << "<g transform=\"matrix(1,0,0,1,50,590)\""<<endl;
    cout << " font-family=\"Arial\" font-size=\"32\">"<<endl;
    
    //cout << "overlap value :" <<boolalpha <<overlap <<endl;
    //cout << "fits:" <<boolalpha <<fits<<endl;
    
    if(!fits)
        cout << "<text x=\"0\" y=\"0\">does not fit</text>" << endl;
    else if(overlap)
        cout << "<text x=\"0\" y=\"0\">overlap</text>" << endl;
    else
        cout << "<text x=\"0\" y=\"0\">ok</text>" << endl;
    
    cout << "</g>"<<endl;
    cout << "</svg>"<<endl;
}
