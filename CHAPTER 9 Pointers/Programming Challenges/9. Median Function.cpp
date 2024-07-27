/* In statistics, when a set of values is sorted in ascending or descending order, its median
is the middle value. If the set contains an even number of values, the median is the
mean, or average, of the two middle values. Write a function that accepts as arguments
the following:
A) An array of integers
B) An integer that indicates the number of elements in the array
The function should determine the median of the array. This value should be returned
as a double. (Assume the values in the array are already sorted.)
Demonstrate your pointer prowess by using pointer notation instead of array notation
in this function. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(double &, int);
void selectionSort(double *, int);
double determineMedian(double *, int);

int main() {

    int numbers,
        amount,
        count;
    double median;

    double *integers = nullptr;

    cout << "How many numbers do you wish to put into the array? ";
    cin >> amount;

    integers = new double[amount];

    cout << "Enter the numbers below:" << endl;
    for (count = 0; count < amount; count++) {
        cout << "Number #" << (count + 1) << ": ";
        integers[count] = checker(*(integers + count), 0);
    }    

    selectionSort(integers, amount);
    cout << "Displaying the contents of the sorted array: ";
    for (int i = 0; i < amount; i++) {
        cout << *(integers + i) << " ";
    }
    cout << endl;

    median = determineMedian(integers, amount);
    cout << endl << "The median is " << median << ". " << endl;

    return 0;
}

int checker(double &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

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

double determineMedian(double *array, int size) {

    double owo = 0;
    int middle, midA, midB;

    if ((size % 2) != 0) {

        cout << "The array is an odd number, this means we can directly take the middle number. ";
        middle = size/2;
        cout << "This would be the #" << (middle + 1) << " number in the array. ";
        owo = *(array + middle);

    }
    else {

        cout << "The array is an even number, this means we need to take the average of the 2 middle numbers. ";
        midA = ((size + 1)/2);
        midB = ((size - 1)/2);
        cout << "This would be the #" << (midB + 1) << " and #" << (midA + 1) << " numbers in the array. ";
        //cout << *(array + midA) << *(array + midB);

        owo = (*(array + midA) + *(array + midB))/2;

    }

    return owo;
}

