/* Write a program that calculates pay for either an hourly paid worker or a salaried
worker. Hourly paid workers are paid their hourly pay rate times the number of hours
worked. Salaried workers are paid their regular salary plus any bonus they may have
earned. The program should declare two structures for the following data:

Hourly Paid:
    HoursWorked
    HourlyRate
Salaried:
    Salary
    Bonus

The program should also declare a union with two members. Each member should be a
structure variable: one for the hourly paid worker and another for the salaried worker.
The program should ask the user whether he or she is calculating the pay for an hourly
paid worker or a salaried worker. Regardless of which the user selects, the appropri-
ate members of the union will be used to store the data that will be used to calculate
the pay.

Input Validation: Do not accept negative numbers. Do not accept values greater than
80 for HoursWorked. */

// this seems too easy
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct HourlyPaid {
    int HoursWorked;
    double HourlyRate;
};

struct Salaried {
    double Salary, Bonus;
};

union worker {
    HourlyPaid hwork;
    Salaried swork;
};

double checker(double&, double);
int checker(int&, int, int);

int main() {

    worker wagie;
    double total = 0;
    char choice;

    cout << "Are you calculating the pay for an hourly paid worker or a salaried worker? " << endl;
    cout << "H for hourly, S for salaried. ";
    cin >> choice;

    choice = toupper(choice);

    if(choice == 'H') {
        cout << "Calculating hourly paid worker... \n";

        cout << "How much is their hourly pay rate? ";
        wagie.hwork.HourlyRate = checker(wagie.hwork.HourlyRate, 0);

        cout << "The number of hours they worked? ";
        wagie.hwork.HoursWorked = checker(wagie.hwork.HoursWorked, 0, 80);

        total = wagie.hwork.HourlyRate * wagie.hwork.HoursWorked;

        cout << "Total: $" << total << endl;

    }
    else if(choice == 'S') {
        cout << "Calculating salaried worker... \n";

        cout << "How much is their regular salary? ";
        wagie.swork.Salary = checker(wagie.swork.Salary, 0);

        cout << "The amount of bonus they may have earned? ";
        wagie.swork.Bonus = checker(wagie.swork.Bonus, 0);

        total = wagie.swork.Salary + wagie.swork.Bonus;

        cout << "Total: $" << total << endl;

    }
    else {
        cout << "WTF" << endl;
    }

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

double checker(double &x, double i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

