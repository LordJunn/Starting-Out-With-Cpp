/* The distance a vehicle travels can be calculated as follows:

distance = speed * time

For example, if a train travels 40 miles per hour for 3 hours, the distance traveled is
120 miles.
Write a program that asks the user for the speed of a vehicle (in miles per hour) and how
many hours it has traveled. The program should then use a loop to display the distance the
vehicle has traveled for each hour of that time period. Here is an example of the output:

What is the speed of the vehicle in mph? 40
How many hours has it traveled? 3
Hour  Distance Traveled
--------------------------------
1     40
2     80
3     120

Input Validation: Do not accept a negative number for speed and do not accept any
value less than 1 for time traveled. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float distance, speed, time;

    cout << "Speed of a vehicle (in miles per hour)?" << endl;
    cin >> speed;

    while (speed < 0) {
        cout << "If I were to travel with negative speed, would I be reversing?" << endl;
        cout << "Speed of a vehicle (in miles per hour)?" << endl;
        cin >> speed;
    }    

    cout << "How many hours it has traveled?" << endl;
    cin >> time;

    while (time <= 0) {
        cout << "Weird, the program doesn't accept any value less than 1." << endl;
        cout << "How many hours it has traveled?" << endl;
        cin >> time;
    }        

    cout << "Hour  Distance Traveled" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 1; i <= time; i++) {

        distance = speed * i;
        cout << i << "      " << distance << endl;
    }

    return 0;
}