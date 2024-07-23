/* Modify the selectionSort function presented in this chapter so it sorts an array
of strings instead of an array of ints. Test the function with a driver program. Use
Program 8-8 as a skeleton to complete. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void selectionSort(string[], int);
void showArray(string[], int);

int main() {
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {
        "Collins, Bill",  "Smith, Bart",   "Allen, Jim",       "Griffin, Jim",
        "Stamey, Marty",  "Rose, Geri",    "Taylor, Terri",    "Johnson, Jill",
        "Allison, Jeff",  "Looney, Joe",   "Wolfe, Bill",      "James, Jean",
        "Weaver, Jim",    "Pore, Bob",     "Rutherford, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon",     "Holland, Beth"};

    selectionSort(names, NUM_NAMES);
    showArray(names, NUM_NAMES);

    return 0;
}

//**************************************************************
// Definition of function selectionSort. *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array. *
//**************************************************************

void selectionSort(string array[], int size) {
    int startScan, minIndex;
    string minValue;

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

//**************************************************************
// Definition of function showArray. *
// This function displays the contents of array. size is the *
// number of elements. *
//**************************************************************

void showArray(string array[], int size) {
    for (int count = 0; count < size; count++) {
        cout << array[count] << endl;
    }
    cout << endl;
}      

int binarySearch(const int array[], int size, int value) {
    int first = 0,        // First array element
        last = size - 1,  // Last array element
        middle,           // Midpoint of search
        position = -1;    // Position of search value
    bool found = false;   // Flag

    while (!found && first <= last) {
        middle = (first + last) / 2;  // Calculate midpoint
        if (array[middle] == value)   // If value is found at mid
        {
            found = true;
            position = middle;
        } else if (array[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;  // If value is in upper half
    }
    return position;
}