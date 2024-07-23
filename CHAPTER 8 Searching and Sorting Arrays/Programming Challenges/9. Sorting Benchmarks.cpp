/* Write a program that uses two identical arrays of at least 20 integers. It should call
a function that uses the bubble sort algorithm to sort one of the arrays in ascending
order. The function should keep a count of the number of exchanges it makes. The
program then should call a function that uses the selection sort algorithm to sort the
other array. It should also keep count of the number of exchanges it makes. Display
these values on the screen. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int SIZE = 20;
int intArray[SIZE] = { 89, 22, 80, 94, 35, 53, 93, 4, 7, 30, 54, 69, 62, 51, 56, 29, 55, 23, 21, 18 };
int intBrray[SIZE] = { 89, 22, 80, 94, 35, 53, 93, 4, 7, 30, 54, 69, 62, 51, 56, 29, 55, 23, 21, 18 };
int count = 0;
int exchange = 0;

int checker(int&, int, int);
void showArray(int[], int);
void selectionSort(int[], int);
void sortArray(int[], int);
void exchanges(int, int);

int main() {

    int value, result;

    cout << "Displaying the array A: ";
    showArray(intArray, SIZE);
    cout << "Displaying the array B: ";
    showArray(intBrray, SIZE);

    cout << "It is now time to sort the arrays in ascending order using bubble sort. " << endl;
    sortArray(intArray, SIZE);
    showArray(intArray, SIZE);
    exchanges(count, exchange);
    cout << endl;

    count = 0; 
    exchange = 0;

    cout << "It is now time to sort the arrays in ascending order using selection sort. " << endl;
    selectionSort(intBrray, SIZE);
    showArray(intBrray, SIZE);
    exchanges(count, exchange);
    cout << endl;

    return 0;
}

//**************************************************************
// Definition of function showArray. *
// This function displays the contents of array. size is the *
// number of elements. *
//**************************************************************

void showArray(int array[], int size) {
    for (int count = 0; count < size; count++) {
        cout << array[count] << " ";
    }
    cout << endl;
}      

void sortArray(int array[], int size) {
    bool swap;
    int temp;

    do {
        swap = false;
        for (int count = 0; count < (size - 1); count++) {
            if (array[count] > array[count + 1]) {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
                exchange++;
            }
        }
        count++;
    } while (swap);
}

//**************************************************************
// Definition of function selectionSort. *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array. *
//**************************************************************

void selectionSort(int array[], int size) {
    int startScan, minIndex;
    int minValue;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
                exchange++;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
        count++;
    }
}

void exchanges(int owo, int uwu) {
    if (owo == 1) {
        cout << "It has made a total of " << owo << " line with ";
    }
    else {
        cout << "It has made a total of " << owo << " lines with ";
    }

    if (uwu == 1) {
        cout << uwu << " exchange. " << endl;
    }
    else {
        cout << uwu << " exchanges. " << endl;
    }
    
}





