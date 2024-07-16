/* A local zoo wants to keep track of how many pounds of food each of its three monkeys
eats each day during a typical week. Write a program that stores this information in a
two-dimensional 3 × 5 array, where each row represents a different monkey and each
column represents a different day of the week. The program should first have the user
input the data for each monkey. Then it should create a report that includes the fol-
lowing information:
• Average amount of food eaten per day by the whole family of monkeys.
• The least amount of food eaten during the week by any one monkey.
• The greatest amount of food eaten during the week by any one monkey.
Input Validation: Do not accept negative numbers for pounds of food eaten. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int MONKEYS = 3;
const int DAYS = 5;

double checker(double&, double); 
double getValues(double array[][DAYS]);
double getAverage(const double array[][DAYS]);
double getLeast(const double array[][DAYS]);
double getMost(const double array[][DAYS]);
double totalFood;


int main() {

    double pounds[MONKEYS][DAYS];
    double avg, least, most;

    getValues(pounds);
    avg = getAverage(pounds);
    least = getLeast(pounds);
    most = getMost(pounds);

    cout << "Total amount of food eaten per day by the whole family of monkeys = " << totalFood << endl;
    cout << "Average amount of food eaten per day by the whole family of monkeys = " << avg << endl;

    cout << "The least amount of food eaten during the week by any one monkey = " << least << endl;
    cout << "The most amount of food eaten during the week by any one monkey = " << most << endl;

    return 0;
}

double checker(double &x, double i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

double getValues(double array[][DAYS]) {

    for(int row = 0; row < MONKEYS; row++) {
        for(int col = 0; col < DAYS; col++) {
            cout << "How many pounds of food did monkey #" << (row + 1) << " eat in day #" << (col + 1) << "? ";
            array[row][col] = checker(array[row][col], -1);
            totalFood += array[row][col];
        }
        cout << endl;
    }
    return totalFood;
}

double getAverage(const double array[][DAYS]) {

    double sum;

    for (int row = 0; row < MONKEYS; row++) {

        for (int col = 0; col < DAYS; col++) {
            sum += array[row][col];
        }
    }
    return (sum/DAYS);
}

double getLeast(const double array[][DAYS]) {

    double sum, localArray[MONKEYS];
    localArray[0] = 0;

    for (int row = 0; row < MONKEYS; row++) {

        sum = 0;       
        for (int col = 0; col < DAYS; col++) {
            sum += array[row][col];
    
        }
        localArray[row] = sum;

    }

    double lowest = localArray[0];

    for (int k = 1; k < MONKEYS; k++) {
        if (localArray[k] <= lowest) {
            lowest = localArray[k];
        }
    }

    return lowest;

}

double getMost(const double array[][DAYS]) {

    double sum, localArray[MONKEYS];
    localArray[0] = 0;

    for (int row = 0; row < MONKEYS; row++) {

        sum = 0;       
        for (int col = 0; col < DAYS; col++) {
            sum += array[row][col];
    
        }
        localArray[row] = sum;

    }

    double highest = localArray[0];

    for (int k = 1; k < MONKEYS; k++) {
        if (localArray[k] >= highest) {
            highest = localArray[k];
        }
    }

    return highest;

}