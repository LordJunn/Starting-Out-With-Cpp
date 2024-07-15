/* Suppose you want to deposit a certain amount of money into a savings account and
then leave it alone to draw interest for the next 10 years. At the end of 10 years you
would like to have $10,000 in the account. How much do you need to deposit today to
make that happen? You can use the following formula, which is known as the present
value formula, to find out:
P = F / 【 (1 + r)^n 】
The terms in the formula are as follows:
• P is the present value, or the amount that you need to deposit today.
• F is the future value that you want in the account. (In this case, F is $10,000.)
• r is the annual interest rate .
• n is the number of years that you plan to let the money sit in the account.
Write a program that has a function named presentValue that performs this calcula-
tion. The function should accept the future value, annual interest rate, and number of
years as arguments. It should return the present value, which is the amount that you
need to deposit today. Demonstrate the function in a program that lets the user experi-
ment with different values for the formula’s terms. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double presentValue(double, double, double);

int main() {

    double future, annual, years, present;

    cout << "The future value that you want in the account? ";
    cin >> future;
    cout << "Annual interest rate (in percentage, so 5% = 5)? ";
    cin >> annual;
    cout << "Number of years that you plan to let the money sit in the account? ";
    cin >> years;

    present = presentValue(future, annual, years);

    cout << fixed << setprecision(2) << "The amount that you need to deposit today = $" << present << endl;

    return 0;
}

double presentValue(double f, double a, double y) {

    a /= 100;
    return f / (pow((1 + a),y));

}