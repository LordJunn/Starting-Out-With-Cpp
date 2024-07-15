/* Suppose you have a certain amount of money in a savings account that earns compound
monthly interest, and you want to calculate the amount that you will have after a spe-
cific number of months. The formula, which is known as the future value formula, is:
F = P * (1 + i)^t
The terms in the formula are as follows:
• F is the future value of the account after the specified time period.
• P is the present value of the account.
• i is the monthly interest rate .
• t is the number of months .
Write a program that prompts the user to enter the account’s present value, monthly
interest rate, and the number of months that the money will be left in the account. The
program should pass these values to a function named futureValue that returns the
future value of the account, after the specified number of months. The program should
display the account’s future value. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double futureValue(double, double, double);

int main() {

    double future, monthly, months, present;

    cout << "The account's present value? ";
    cin >> present;
    cout << "Monthly interest rate (keep it low since its monthly)? ";
    cin >> monthly;
    cout << "Number of months that the money will be left in the account? ";
    cin >> months;

    future = futureValue(present, monthly, months);

    cout << fixed << setprecision(2) << "The amount's future value = $" << future << endl;

    return 0;
}

double futureValue(double p, double i, double t) {

    i /= 100;
    return p * pow((1 + i),t);

}