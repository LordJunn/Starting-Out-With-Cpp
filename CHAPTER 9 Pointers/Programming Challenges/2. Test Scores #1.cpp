/* Write a program that dynamically allocates an array large enough to hold a user-
defined number of test scores. Once all the scores are entered, the array should be
passed to a function that sorts them in ascending order. Another function should be
called that calculates the average score. The program should display the sorted list of
scores and averages with appropriate headings. Use pointer notation rather than array
notation whenever possible.
Input Validation: Do not accept negative numbers for test scores. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(double&, int, int);
void getArrayInfo(double*, int);
void selectionSort(double*, int);
double average(double, int);

int main() {

    double *scoresArray = nullptr,
            scores,
            avg;

    int amount, 
        count, 
        total = 0;

    cout << "How many test scores do you wish to put into the array? ";
    cin >> amount;

    scoresArray = new double[amount];

    cout << "Enter the test scores below:" << endl;
    getArrayInfo(scoresArray, amount);

    selectionSort(scoresArray, amount);
    cout << "Displaying the contents of the sorted test scores: ";
    for (int i = 0; i < amount; i++) {
        cout << *(scoresArray + i) << " ";
        total += *(scoresArray + i);
    }
    cout << endl;

    avg = average(total, amount);
    cout << "Average of the test scores: " << avg;

    delete[] scoresArray;
    scoresArray = nullptr;

    return 0;
}

int checker(double &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getArrayInfo(double *array, int amount) {

    for (int i = 0; i < amount; i++) {
        cout << "Test score #" << (i + 1) << ": ";
        *(array + i) = checker(*(array + i), 0, 100);
    }    
}

void selectionSort(double *array, int size) {
    int startScan, minIndex;
    int minValue;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

double average(double total, int amount) {

    double avg = total/amount;
    return avg;

}

