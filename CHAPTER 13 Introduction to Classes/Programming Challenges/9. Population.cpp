/* In a population, the birth rate and death rate are calculated as follows:
Birth Rate = Number of Births ÷ Population
Death Rate = Number of Deaths ÷ Population
For example, in a population of 100,000 that has 8,000 births and 6,000 deaths per
year, the birth rate and death rate are:
Birth Rate = 8,000 ÷ 100,000 = 0.08
Death Rate = 6,000 ÷ 100,000 = 0.06
Design a Population class that stores a population, number of births, and number of
deaths for a period of time. Member functions should return the birth rate and death
rate. Implement the class in a program.

Input Validation: Do not accept population figures less than 1, or birth or death num-
bers less than 0. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Population{
   private:
    double pop, birth, death;

   public:
    Population(double p, double b, double d) {
        pop = p;
        birth = b;
        death = d;
    }

    double BR() {
        return birth/pop;
    }

    double DR() {
        return death/pop;
    }

};

double checker(double&, double);

int main() {

    double po, bi, de;

    cout << "Population? ";
    po = checker(po, 0);
    cout << "Number of births? ";
    bi = checker(bi, 0);
    cout << "Number of deaths? ";
    de = checker(de, 0);

    Population popu(po, bi, de);

    cout << "Birth rate: " << popu.BR() << endl;
    cout << "Death rate: " << popu.DR() << endl;

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
