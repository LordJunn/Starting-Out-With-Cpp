/* In a population, the birth rate is the percentage increase of the population due to births,
and the death rate is the percentage decrease of the population due to deaths. Write a
program that displays the size of a population for any number of years. The program
should ask for the following data:
• The starting size of a population
• The annual birth rate
• The annual death rate
• The number of years to display
Write a function that calculates the size of the population for a year. The formula is
N = P + BP − DP
where N is the new population size, P is the previous population size, B is the birth rate,
and D is the death rate.

Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
negative numbers for birth rate or death rate. Do not accept numbers less than 1 for
the number of years. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int); // i love this one
double popSize(double, double, double, int);

int main() {

    int start, birth, death, years, newp, bs, ds, 
        bt = 0, 
        dt = 0;

    cout << "The starting size of a population? ";
    start = checker(start, 1);
    cout << "The annual birth rate in percentage? ";
    birth = checker(birth, -1);
    cout << "The annual death rate in percentage? ";
    death = checker(death, -1);
    cout << "The number of years to display? ";
    years = checker(years, 0);

    for (int i = 1; i <= years; i++) {
        newp = popSize(start, birth, death, i);
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

double popSize(double s, double b, double d, int y) {

    double bs = 0, ds = 0, newp;

    b /= 100;
    d /= 100;

    bs = b * s;
    ds = d * s;

    newp = (s * (1 + b) * (1 - d)) * y;
    return bs, ds, newp; // how tf it keeps coming out 174

}