/* Write a program that converts Celsius temperatures to Fahrenheit temperatures. The
formula is
F = (9/5)C + 32
F is the Fahrenheit temperature, and C is the Celsius temperature. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    float farenheit, celsius;

    cout << "Insert the Celsius temperatures that you want to convert to Fahrenheit temperatures" << endl;
    cin >> celsius;

    farenheit = ((9.0/5.0) * celsius) + 32;

    cout << "The Fahrenheit temperatures is " << farenheit << endl;

    return 0;
}