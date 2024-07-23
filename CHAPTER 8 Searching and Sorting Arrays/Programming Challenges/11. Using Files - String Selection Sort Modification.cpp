/* Modify the program you wrote for Programming Challenge 6 so it reads in 20 strings
from a file. The data can be found in the names.txt file. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void selectionSort(string[], int);
void showArray(string[], int);

int main() {
    const int NUM_NAMES = 40;
    string names[NUM_NAMES];
    int count = 0;
    ifstream inputFile; 

    // Open the file.
    inputFile.open("names.txt");

    // Read the numbers from the file into the array.
    while (count < NUM_NAMES && inputFile >> names[count]) { 
        count++;
    }

    // Close the file.
    inputFile.close();

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

