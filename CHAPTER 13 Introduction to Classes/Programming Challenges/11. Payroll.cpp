/* Design a PayRoll class that has data members for an employee’s hourly pay rate,
number of hours worked, and total pay for the week. Write a program with an array of
seven PayRoll objects. The program should ask the user for the number of hours each
employee has worked and will then display the amount of gross pay each has earned.

Input Validation: Do not accept values greater than 60 for the number of hours
worked. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class PayRoll {
   private:
    double hourly;
    int hours;
    double gross;
    int elements;

   public:
    void grossing(double hly, int h) {
        double g = hly * static_cast<double>(h);
        gross = g;
    }

    double displayGross() {
        return gross;
    }

};

double checker(double&, double);
int checker(int&, int, int);

int main() {

    int elements = 7;
    PayRoll pay[elements];
    double hrly;
    int hrs;

    for(int i = 0; i < elements; i++) {
        cout << "How much is employee #" << (i + 1) << "'s hourly rate? ";
        hrly = checker(hrly, 0);
        cout << "How many hours did employee #" << (i + 1) << "'s work? ";
        hrs = checker(hrs, 0, 60);

        pay[i].grossing(hrly, hrs);
    }

    for(int i = 0; i < elements; i++) {
        cout << "Employee #" << (i + 1) << "'s gross pay: $" << pay[i].displayGross() << endl; 
    }

    return 0;
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

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but bigger than " << j << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}
