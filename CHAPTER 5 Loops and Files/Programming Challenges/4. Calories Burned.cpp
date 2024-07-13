/* Running on a particular treadmill you burn 3.6 calories per minute. Write a program that
uses a loop to display the number of calories burned after 5, 10, 15, 20, 25, and 30 minutes. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const float burn = 3.6;

    for (int i = 1; i <= 30; i++) {

        if (i % 5 == 0) {
            cout << "Running for " << i << " minutes burns around " << (i * burn) << " calories.";
            cout << endl;
        }

    }    

    return 0;
}