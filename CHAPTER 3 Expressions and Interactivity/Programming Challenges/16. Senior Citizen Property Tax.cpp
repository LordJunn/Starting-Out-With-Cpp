/* Madison County provides a $5,000 homeowner exemption for its senior citizens. For
example, if a senior’s house is valued at $158,000 its assessed value would be $94,800,
as explained above. However, he would only pay tax on $89,800. At last year’s tax
rate of $2.64 for each $100 of assessed value, the property tax would be $2,370.72. In
addition to the tax break, senior citizens are allowed to pay their property tax in four
equal payments. The quarterly payment due on this property would be $592.68. Write
a program that asks the user to input the actual value of a piece of property and the
current tax rate for each $100 of assessed value. The program should then calculate
and report how much annual property tax a senior homeowner will be charged for this
property and what the quarterly tax bill will be. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    float value, rate, assessment, tax, quarterly;

    cout << "How much is the property valued at?" << endl;
    cin >> value;

    cout << "What is the current tax rate for each $100 of assessed value?" << endl;
    cin >> rate;

    assessment = (value * 0.60) - 5000.00;
    tax = assessment * (rate/100.0);
    quarterly = tax/4;

    cout << fixed << setprecision(2) << "Assessment value: $" << assessment << endl
                                     << "Property tax: $" << tax << endl
                                     << "Quarterly tax bill: $" << quarterly << endl;


    return 0;
}