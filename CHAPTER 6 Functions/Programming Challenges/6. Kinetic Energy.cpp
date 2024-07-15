/* In physics, an object that is in motion is said to have kinetic energy. The following
formula can be used to determine a moving object’s kinetic energy:
KE = 1/2 * m * (v*2)
The variables in the formula are as follows: KE is the kinetic energy, m is the object’s
mass in kilograms, and v is the object’s velocity, in meters per second.
Write a function named kineticEnergy that accepts an object’s mass (in kilograms)
and velocity (in meters per second) as arguments. The function should return the
amount of kinetic energy that the object has. Demonstrate the function by calling it in
a program that asks the user to enter values for mass and velocity. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double kineticEnergy(double, double);

int main() {

    double mass, velocity, KE;

    cout << "Object's mass? ";
    cin >> mass;
    cout << "Object's velocity? ";
    cin >> velocity;

    KE = kineticEnergy(mass, velocity);

    cout << "The kinetic energy for the object is " << KE << " joules.";

    return 0;
}

double kineticEnergy(double mass, double velocity) {

    return 0.5 * mass * (pow(velocity, 2));
}