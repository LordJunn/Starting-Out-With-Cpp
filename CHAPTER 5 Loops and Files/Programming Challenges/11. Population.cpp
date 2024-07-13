/* Write a program that will predict the size of a population of organisms. The program
should ask the user for the starting number of organisms, their average daily popula-
tion increase (as a percentage), and the number of days they will multiply. A loop
should display the size of the population for each day.

Input Validation: Do not accept a number less than 2 for the starting size of the popu-
lation. Do not accept a negative number for average daily population increase. Do not
accept a number less than 1 for the number of days they will multiply. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float start = 0,
        avg = 0,
        days = 0;

    float mult, realavg, total, inc;

    cout << "Starting number of organisms?" << endl;
    cin >> start;

    while (start < 2) {
        
        cout << "I don't think it can reproduce with less than 2." << endl;
        cout << "Starting number of organisms?" << endl;
        cin >> start;   

    }    

    cout << "Their average daily population increase (as a percentage)?" << endl;
    cin >> avg;

    while (avg < 2) {
        
        cout << "Instead of breeding, it kills itself." << endl;
        cout << "Their average daily population increase (as a percentage)?" << endl;
        cin >> avg;   

    }        

    cout << "The days they will multiply for?" << endl;
    cin >> days;

    while (days < 1) {
        
        cout << "I can't give birth that fast." << endl;
        cout << "The days they will multiply for?" << endl;
        cin >> days;  

    }      

    for (int i = 1; i <= days; i++) {

        if (total == 0) {
            total = start;
        }

        realavg = avg/100;

        inc = (total * realavg);
        total += inc;

        cout << "Day " << i << "'s population = " << total << endl;

    }

    return 0;
}