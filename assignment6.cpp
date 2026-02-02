#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
    string color;

public:
    Shape(const string &c) : color(c) {}
    string getColor() const
    {
        return color;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(const string &c, double r) : Shape(c), radius(r) {}

    double area() const
    {
        return 3.14 * radius * radius;
    }

    double circumference() const
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(const string &c, double w, double h) : Shape(c), width(w), height(h) {}

    double area() const
    {
        return width * height;
    }

    double perimeter() const
    {
        return 2 * (width + height);
    }
};

int main()
{
    Circle circle("Red", 7);
    Rectangle rectangle("Blue", 2, 4);

    cout << "Circle color: " << circle.getColor() << endl;
    cout << "Circle area: " << circle.area() << endl;
    cout << "Circle circumference: " << circle.circumference() << endl;

    cout << "Rectangle color: " << rectangle.getColor() << endl;
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Rectangle perimeter: " << rectangle.perimeter() << endl;

    return 0;
}
