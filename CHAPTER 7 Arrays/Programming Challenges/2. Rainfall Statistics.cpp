/* Write a program that lets the user enter the total rainfall for each of 12 months into
an array of doubles. The program should calculate and display the total rainfall for
the year, the average monthly rainfall, and the months with the highest and lowest
amounts.

Input Validation: Do not accept negative numbers for monthly rainfall figures. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double checker(double&, int); 
double getValues(double array[]);
int larger(double array[]);
int smaller(double array[]);
double average(double);

const int months = 12;

int main() { // some stuff stolen from PC1 C7
    
    double rainfall[months];
    double total = getValues(rainfall);

    cout << "Total rainfall = " << total << endl;

    int largest = larger(rainfall);
    cout << "Highest rainfall = " << largest << endl;
    int smallest = smaller(rainfall);
    cout << "Lowest rainfall = " << smallest << endl;
    int avg = average(total);
    cout << "Average rainfall = " << avg << endl;

    return 0;

}

double checker(double &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

double getValues(double array[]) {

    int total = 0;

    for(int i = 0; i < months; i++) {
        cout << "Enter rainfall for month " << (i + 1) << " here. ";
        array[i] = checker(array[i], -1);
        total += array[i];
    }    

    return total;
}

int larger(double array[]) {

    int lcount = 0;
    int larger = array[0];
    for (int i = 1; i < months; i++)
    {
        if (array[i] >= larger) {
            larger = array[i];
            lcount++;
        }
    }
    cout << "There were a total of " << lcount << " numbers larger than " << array[0] << endl;
    return larger;

}

int smaller(double array[]) {

    int scount = 0;
    int smaller = array[0];
    for (int i = 1; i < months; i++)
    {
        if (array[i] <= smaller) {
            smaller = array[i];
            scount++;
        }
    }
    cout << "There were a total of " << scount << " numbers smaller than " << array[0] << endl;
    return smaller;
    
}

double average(double total) {

    int avg = total/months;
    return avg;

}