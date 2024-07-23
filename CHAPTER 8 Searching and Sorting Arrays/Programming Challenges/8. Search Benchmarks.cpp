/* Write a program that has an array of at least 20 integers. It should call a function that
uses the linear search algorithm to locate one of the values. The function should keep
a count of the number of comparisons it makes until it finds the value. The program
then should call a function that uses the binary search algorithm to locate the same
value. It should also keep count of the number of comparisons it makes. Display these
values on the screen. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int SIZE = 20;
int intArray[SIZE] = { 89, 21, 80, 94, 35, 53, 93, 4, 7, 29, 53, 69, 62, 51, 55, 29, 55, 23, 21, 18 };
int count = 0;

int checker(int&, int, int);
void showArray(int[], int);
int searchList(const int[], int, int);
void selectionSort(int[], int);
int binarySearch(int[], int, int);
void comparisons(int);
void results(int);

int main() {

    int value, result;

    cout << "Displaying the array." << endl;
    showArray(intArray, SIZE);

    cout << "Enter the value you want to find in the array. ";
    value = checker(value, 0, 100);   
        
    result = searchList(intArray, SIZE, value);
    cout << "Using linear search: ";
    results(result);
    comparisons(count);
    cout << endl;

    count = 0;

    cout << "It is now time to sort the arrays in ascending order. ";
    selectionSort(intArray, SIZE);
    showArray(intArray, SIZE);
    result = binarySearch(intArray, SIZE, value);
    cout << "Using binary search: ";
    results(result);
    comparisons(count);
    cout << endl;

    count = 0;

    result = searchList(intArray, SIZE, value);
    cout << "Using linear search (after sorting ascendingly): ";
    results(result);
    comparisons(count);
    cout << endl;

    return 0;
}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

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

//*****************************************************************
// The searchList function performs a linear search on an *
// integer array. The array list, which has a maximum of numElems *
// elements, is searched for the number stored in value. If the *
// number is found, its array subscript is returned. Otherwise, *
// -1 is returned indicating the value was not in the array. *
//******************************************************************

int searchList(const int list[], int numElems, int value) {
    int index = 0;       // Used as a subscript to search array
    int position = -1;   // To record position of search value
    bool found = false;  // Flag to indicate if the value was found

    while (index < numElems && !found) {
        if (list[index] == value)  // If the value is found
        {
            found = true;      // Set the flag
            position = index;  // Record the value's subscript
        }
        index++;  // Go to the next element
        count++;
    }
    return position;  // Return the position, or -1
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
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

int binarySearch(int array[], const int size, int value) {
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
            count++;
        } else if (array[middle] > value) {
            // If value is in lower half
            last = middle - 1;
            count++;    
        } 
        else {
            first = middle + 1;  // If value is in upper half
            count++;
        }
            
    }
    return position;
}

void results(int results) {
    if (results == -1)
        cout << "Integer is not found\n";
    else {
        cout << "The integer is found in position ";
        cout << (results + 1) << endl;
    }
}

void comparisons(int owo) {
    if (owo == 1) {
        cout << "It has made a total of " << owo << " comparision. " << endl;
    }
    else {
        cout << "It has made a total of " << owo << " comparisions. " << endl;
    }
    
}
