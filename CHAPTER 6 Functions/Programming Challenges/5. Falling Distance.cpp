/* When an object is falling because of gravity, the following formula can be used to
determine the distance the object falls in a specific time period:
d = (1/2) g(t^2)
The variables in the formula are as follows: d is the distance in meters, g is 9.8, and t
is the amount of time, in seconds, that the object has been falling.
Write a function named fallingDistance that accepts an object’s falling time (in
seconds) as an argument. The function should return the distance, in meters, that the
object has fallen during that time interval. Write a program that demonstrates the
function by calling it in a loop that passes the values 1 through 10 as arguments and
displays the return value. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double fallingDistance(int);

int main() {

    double distance, seconds;

    cout << "Objects falling time?" << endl;
    cin >> seconds;

    for (int i = 1; i <= seconds; i++) {

        distance = fallingDistance(i);
        cout << "When " << i << "s has passed, object has fell " << distance << " meters." << endl;
    
        }

    return 0;
}

double fallingDistance(int seconds) {

    return 0.5 * (9.8 * (pow(seconds, 2)));

}