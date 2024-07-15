/* The formula for converting a temperature from Fahrenheit to Celsius is
C = 5/9 * (F - 32)
where F is the Fahrenheit temperature and C is the Celsius temperature. Write a func-
tion named celsius that accepts a Fahrenheit temperature as an argument. The func-
tion should return the temperature, converted to Celsius. Demonstrate the function by
calling it in a loop that displays a table of the Fahrenheit temperatures 0 through 20
and their Celsius equivalents. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double celcius(int);

int main() { // semi stolen from PC5 C6

    double fs, fe, c;

    cout << "Starting farenheit temperature? ";
    cin >> fs;
    cout << "Ending farenheit temperature? ";
    cin >> fe;

    for (int i = fs; i <= fe; i++) {
        
        fs = i;
        c = celcius(fs);
        cout << fixed << setprecision(2) << "When farenheit is " << fs << ", it is " << c << " in celcius." << endl;

    }

    return 0;
}

double celcius(int fs) { // cant we do this with a normal for loop

    return (5.0/9.0) * (fs - 32);

}