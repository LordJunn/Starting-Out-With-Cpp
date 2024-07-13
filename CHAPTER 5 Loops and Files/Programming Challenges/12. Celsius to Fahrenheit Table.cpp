/* In Programming Challenge 10 of Chapter 3 you were asked to write a program that
converts a Celsius temperature to Fahrenheit. Modify that program so it uses a loop
to display a table of the Celsius temperatures 0–20, and their Fahrenheit equivalents. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std; //actually its PC12 C3

int main() {

    float farenheit, celsius;

    int max = 20;

    cout << "Celcius        Farenheit" << endl; // stolen from PC6 C5
    cout << "--------------------------------" << endl;    

    for (int i = 0; i <= max; i++) {
        farenheit = ((9.0/5.0) * i) + 32;
        cout << setw(2) << i << "             " << farenheit << endl;
    }

    return 0;
}