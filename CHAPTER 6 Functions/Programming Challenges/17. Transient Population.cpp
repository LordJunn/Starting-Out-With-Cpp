/* Modify Programming Challenge 16 to also consider the effect on population caused by
people moving into or out of a geographic area. Given as input a starting population
size, the annual birth rate, the annual death rate, the number of individuals who typi-
cally move into the area each year, and the number of individuals who typically leave
the area each year, the program should project what the population will be numYears
from now. You can either prompt the user to input a value for numYears, or you can
set it within the program.
Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
negative numbers for birth rate, death rate, arrivals, or departures. */


// most stuff stolen from PC16 C6
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int); // i love this one
double popSize(double, double, double, int, int, int);

int main() {

    int start, birth, death, years, newp, in, out;

    cout << "The starting size of a population? ";
    start = checker(start, 1);
    cout << "The annual birth rate in percentage? ";
    birth = checker(birth, -1);
    cout << "The annual death rate in percentage? ";
    death = checker(death, -1);
    cout << "Number of individuals who typically move into the area each year? ";
    in = checker(in, -1);
    cout << "Number of individuals who typically leave the area each year? ";
    out = checker(out, -1);
    cout << "The number of years to display? ";
    years = checker(years, 0);

    for (int i = 1; i <= years; i++) {
        newp = popSize(start, birth, death, i, in, out);
        cout << "At year " << i << ", the population is: " << newp << endl;
    }

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin >> x;
    }

    return x;

}

double popSize(double s, double b, double d, int y, int i, int o) {

    double bs = 0, ds = 0, newp;

    b /= 100;
    d /= 100;

    bs = b * s;
    ds = d * s;

    newp = ((s * (1 + b) * (1 - d)) * y) + i - o;
    return bs, ds, newp;

}