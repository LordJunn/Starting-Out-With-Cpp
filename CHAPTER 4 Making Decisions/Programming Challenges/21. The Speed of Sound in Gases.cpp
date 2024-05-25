/* When sound travels through a gas, its speed depends primarily on the density of the
medium. The less dense the medium, the faster the speed will be. The following table
shows the approximate speed of sound at 0 degrees centigrade, measured in meters per
second, when traveling through carbon dioxide, air, helium, and hydrogen.

Medium            Speed (Meters per Second)
Carbon Dioxide    258.0
Air               331.5
Helium            972.0
Hydrogen          1,270.0

Write a program that displays a menu allowing the user to select one of these four
gases. After a selection has been made, the user should enter the number of seconds it
took for the sound to travel in this medium from its source to the location at which it
was detected. The program should then report how far away (in meters) the source of
the sound was from the detection location.

Input Validation: Check that the user has selected one of the available menu choices.
Do not accept times less than 0 seconds or more than 30 seconds. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const double co2 = 258.0,
                 h2o = 331.5,
                 h2 = 927.0,
                 h = 1270.0;

    int menu, seconds, distance;

    cout << "Select 1 for Carbon Dioxide, 2 for Air, 3 for Helium and 4 for Hydrogen." << endl;
    cin >> menu;    

    switch(menu) {

        case 1:

        cout << "Enter the number of seconds it took " << 
        "for the sound to travel in this medium from " << 
        "its source to the location at which it was detected." << endl;

        cin >> seconds;

        if(seconds >= 0 && seconds <= 30) {

            distance = seconds * co2;
            cout << distance << " meters." << endl;
        }
        else {
            cout << "???" << endl;
        }

        break;

        case 2:
        
        cout << "Enter the number of seconds it took " << 
        "for the sound to travel in this medium from " << 
        "its source to the location at which it was detected." << endl;

        cin >> seconds;

        if(seconds >= 0 && seconds <= 30) {

            distance = seconds * h2o;
            cout << distance << " meters." << endl;
        }
        else {
            cout << "???" << endl;
        }

        break;

        case 3:
        
        cout << "Enter the number of seconds it took " << 
        "for the sound to travel in this medium from " << 
        "its source to the location at which it was detected." << endl;

        cin >> seconds;

        if(seconds >= 0 && seconds <= 30) {

            distance = seconds * h2;
            cout << distance << " meters." << endl;
        }
        else {
            cout << "???" << endl;
        }

        break;

        case 4:
        
        cout << "Enter the number of seconds it took " << 
        "for the sound to travel in this medium from " << 
        "its source to the location at which it was detected." << endl;

        cin >> seconds;

        if(seconds >= 0 && seconds <= 30) {

            distance = seconds * h;
            cout << distance << " meters." << endl;
        }
        else {
            cout << "???" << endl;
        }

        break;        

        default:

        cout << "???" << endl;

        break;

    }

    return 0;
}