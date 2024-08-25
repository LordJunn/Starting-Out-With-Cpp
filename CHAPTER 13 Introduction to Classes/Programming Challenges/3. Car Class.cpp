/* Write a class named Car that has the following member variables:
• yearModel. An int that holds the car’s year model.
• make. A string that holds the make of the car.
• speed. An int that holds the car’s current speed.
In addition, the class should have the following constructor and other member functions.
• Constructor. The constructor should accept the car’s year model and make as argu-
ments. These values should be assigned to the object’s yearModel and make member
variables. The constructor should also assign 0 to the speed member variables.
• Accessor. Appropriate accessor functions to get the values stored in an object’s
yearModel, make, and speed member variables.
• accelerate. The accelerate function should add 5 to the speed member variable
each time it is called.
• brake. The brake function should subtract 5 from the speed member variable each
time it is called.
Demonstrate the class in a program that creates a Car object, and then calls the
accelerate function five times. After each call to the accelerate function, get
the current speed of the car and display it. Then, call the brake function five times.
After each call to the brake function, get the current speed of the car and display it. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Car {
   private:
    int yearModel;
    string make;
    int speed;

   public:
    Car(int, string);

    int getYear() const {
        return yearModel;
    }
    string getMake() const {
        return make;
    }
    int getSpeed() const {
        return speed;
    }

    void accelerate(int s) {
        speed += 5;
        cin.get();
    }

    void brake(int s) {
        speed -= 5;
        cin.get();
    }


};

Car::Car(int y, string m) {
    yearModel = y;
    make = m;
    speed = 0;
}

int main() {

    int y, s;
    string m;

    int zoomer = 5;

    Car kereta(2024, "Poton Maibi");
    cout << "This is our car: " << kereta.getYear() << " " << kereta.getMake() << " " << kereta.getSpeed() << endl;

    for(int i = 0; i < zoomer; i++) {
        cout << "Accelerating... \n";
        kereta.accelerate(s);
        cout << "Current speed after " << (i + 1) << "x acceleration: " << kereta.getSpeed() << endl;
    }

    cout << "Final accelerate speed: " << kereta.getSpeed() << endl; 

    for(int i = 0; i < zoomer; i++) {
        cout << "Braking... \n";
        kereta.brake(s);
        cout << "Current speed after " << (i + 1) << "x braking: " << kereta.getSpeed() << endl;
    }   

    cout << "Final brake speed: " << kereta.getSpeed(); 

    return 0;
}