/* Write a program that asks the user to enter the monthly costs for the following
expenses incurred from operating his or her automobile: loan payment, insurance, gas,
oil, tires, and maintenance. The program should then display the total monthly cost of
these expenses, and the total annual cost of these expenses. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    int loan, insurance, gas, oil, tires, maintenance, month, year;

    cout << "Enter the monthly costs for the following expenses incurred from operating your automobile, starting with" << endl;
    cout << "Loan payment:" << endl;
    cin >> loan;

    cout << "Insurance:" << endl;
    cin >> insurance;

    cout << "Gas:" << endl;
    cin >> gas;

    cout << "Oil:" << endl;
    cin >> oil;

    cout << "Tires:" << endl;
    cin >> tires;

    cout << "Maintenance:" << endl;
    cin >> maintenance;    

    month = loan + insurance + gas + oil + tires + maintenance;
    year = month * 12;

    cout << "The total monthly cost of these would be $" << month << endl;
    cout << "The total yearly cost of these would be $" << year << endl;

    return 0;
}