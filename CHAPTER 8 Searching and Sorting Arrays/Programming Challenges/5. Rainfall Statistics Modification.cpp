/* Modify the Rainfall Statistics program you wrote for Programming Challenge 2 of
Chapter 7. The program should display a list of months, sorted in order of rainfall,
from highest to lowest. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double checker(double&, int); 
double getValues(double array[], int[]);
int larger(double array[]);
int smaller(double array[]);
double average(double);
void dualSort(int[], double[], int);
void showArray(const double[], int[], int); 

const int months = 12;

int main() { // some stuff stolen from PC1 C7
    
    double rainfall[months];
    int month[months] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    double total;
    
    total = getValues(rainfall, month);

    cout << "Total rainfall = " << total << endl;

    int largest = larger(rainfall);
    cout << "Highest rainfall = " << largest << endl;
    int smallest = smaller(rainfall);
    cout << "Lowest rainfall = " << smallest << endl;
    int avg = average(total);
    cout << "Average rainfall = " << avg << endl;

    dualSort(month, rainfall, months);
    showArray(rainfall, month, months);


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

double getValues(double array[], int b[]) {

    int total = 0;
    int owo = 0;

    for(int i = 0; i < months; i++) {
        cout << "Enter rainfall for month " << (b[i]) << " here. ";
        array[i] = checker(array[i], -1);
        owo = i;
        b[i] = (b[owo] + 1);
        total += array[i];
        owo = 0;
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

void dualSort(int month[], double rainfall[], int size) {
    int startScan, maxIndex, tempid;
    double maxValue;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        maxIndex = startScan;
        maxValue = rainfall[startScan];
        tempid = month[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (rainfall[index] > maxValue) {
                maxValue = rainfall[index];
                tempid = month[index];
                maxIndex = index;
            }
        }
        rainfall[maxIndex] = rainfall[startScan];
        month[maxIndex] = month[startScan];
        rainfall[startScan] = maxValue;
        month[startScan] = tempid;
    }
}

void showArray(const double array[], int b[], int size) {
    cout << "Displaying the months with the highest rainfaill, ascending order." << endl;
    for (int count = 0; count < size; count++) {
        cout << "Month: "<< (b[count] - 1) << ", Rainfall: " << array[count] << endl;
    }
    cout << endl;
}








