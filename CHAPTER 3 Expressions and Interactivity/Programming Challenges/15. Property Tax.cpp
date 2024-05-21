/* A county collects property taxes on the assessment value of property, which is 60 per-
cent of the property’s actual value. If an acre of land is valued at $10,000, its assessment
value is $6,000. The property tax is then 75¢ for each $100 of the assessment value.
The tax for the acre assessed at $6,000 will be $45. Write a program that asks for the
actual value of a piece of property and displays the assessment value and property tax. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    float value, assessment, tax;

    cout << "How much is the land valued at?" << endl;
    cin >> value;

    assessment = value * 0.60;
    tax = assessment * 0.0075;

    cout << fixed << setprecision(2) << "Assessment value: $" << assessment << endl
                                     << "Property tax: $" << tax << endl;

    return 0;
}