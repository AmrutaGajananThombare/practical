#include <iostream>
using namespace std;

double area(double radius)
 {
   return 3.14159 * radius * radius;
 }

double area(double length, double breadth)
 {
  return length * breadth;
 }

double areaTriangle(double base,double height)
 {
  return 0.5 * base *height;
 }

double volume(double length, double breadth = 1, double height = 1)
 {
  return length* breadth * height;
 }

int main()
 {
   cout << "Area of circle (radius = 5): " << area(5) << endl;
   cout << "Area of rectangle (length = 4, breadth = 6 ): " << area(4, 6) << endl;
   cout << "Area of triangle (base = 3, heigth= 7): " << areaTriangle (3, 7) << endl ;
   
   cout << "Volume of box (3, 4, 5): " << volume(3, 4, 5) << endl;
   cout << "Volume of box (3, 4): " << volume(3, 4) << endl;
   cout << "Volume of box (3): " << volume(3) << endl;
   return 0;
 }  
