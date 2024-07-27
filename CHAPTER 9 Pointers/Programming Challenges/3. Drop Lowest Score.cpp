/* Modify Problem 2 above so the lowest test score is dropped. This score should not be
included in the calculation of the average. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(double&, int, int);
void getArrayInfo(double*, int);
void selectionSort(double*, int);
int smaller(double*, int);
double average(double, int);

int main() {

    double *scoresArray = nullptr,
            scores,
            avg;

    int amount, 
        count, 
        total = 0,
        smallest;

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

    smallest = smaller(scoresArray, amount);
    total -= smallest;
    amount--;

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

int smaller(double *array, int amount) {

    int scount = 0;
    int smaller = array[0];
    for (int i = 1; i < amount; i++)
    {
        if (array[i] <= smaller) {
            smaller = array[i];
        }
    }
    return smaller;
    
}
