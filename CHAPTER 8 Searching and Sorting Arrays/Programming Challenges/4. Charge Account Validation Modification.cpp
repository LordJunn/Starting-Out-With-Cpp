/* Modify the program you wrote for Problem 1 (Charge Account Validation) so it per-
forms a binary search to locate valid account numbers. Use the selection sort algorithm
to sort the array before the binary search is performed. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int binarySearch(const int[], int, int);
int checker(int&, int, int); // is checker necessary actually
void selectionSort(int[], int);
const int SIZE = 18;

int main() {

    int results, value;
    int numbers[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                        1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };

    cout << "Enter a charge account number. " << endl;
    value = checker(value, 1000000, 9999999);
    selectionSort(numbers, SIZE);
    results = binarySearch(numbers, SIZE, value);

    if(results == -1) {
        cout << "The number is invalid." << endl;
    }
    else {
        cout << "The number is valid." << endl;
        cout << "It is the #" << (results + 1) << " number in ascending order. " << endl;
    }

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

void selectionSort(int array[], int size) {
    int startScan, minIndex, minValue;

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
