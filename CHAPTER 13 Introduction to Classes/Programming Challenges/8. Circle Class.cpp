/* Write a Circle class that has the following member variables:
• radius: a double
• pi: a double initialized with the value 3.14159
The class should have the following member functions:
• Default Constructor. A default constructor that sets radius to 0.0. 
• Constructor. Accepts the radius of the circle as an argument.
• setRadius. A mutator function for the radius variable.
• getRadius. An accessor function for the radius variable.
• getArea. Returns the area of the circle, which is calculated as
area = pi * radius * radius
• getDiameter. Returns the diameter of the circle, which is calculated as
diameter = radius * 2
• getCircumference. Returns the circumference of the circle, which is calculated as
circumference = 2 * pi * radius
Write a program that demonstrates the Circle class by asking the user for the circle’s
radius, creating a Circle object, and then reporting the circle’s area, diameter, and
circumference. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Circle {
   private:
    double radius;
    double pi = 3.14159;

   public:
    Circle() {
        radius = 0.0;
    }

    Circle(double r) { // Constructor
        radius = r;
    }
    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const { 
        return radius; 
    }

    double getPi() const { 
        return pi; 
    }

    double getCircumference() {
        return (radius * pi * 2);
    }

    double getDiameter() {
        return (radius * 2);
    }

    double getArea() const { 
        return radius * pi;
    }
};

int main() {

    double jejari;

    cout << "Radius of the circle? ";
    cin >> jejari;

    Circle bulat(jejari);
    bulat.setRadius(jejari);

    cout << "Area = " << bulat.getArea() << endl;
    cout << "Diameter = " << bulat.getDiameter() << endl;
    cout << "Circumference = " << bulat.getCircumference() << endl;

    return 0;
}