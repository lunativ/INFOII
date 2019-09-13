//============================================================================
// Name        : Clases_copia.cpp
// Author      : VL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream >
using namespace std;
class Point {
    int x;
public:
    Point(int x) { this->x = x; cout << "Constructor ordinario"<<endl;}
    Point(const Point &p) { x = p.x;cout << "Constructor de copia"<<endl;}
    int getX() { return x; }
};

int main()
{
   Point p1(10);
   Point p2 = p1;
   cout << p2.getX();
   return 0;
}
