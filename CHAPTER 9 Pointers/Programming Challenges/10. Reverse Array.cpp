/* Write a function that accepts an int array and the array’s size as arguments. The func-
tion should create a copy of the array, except that the element values should be reversed
in the copy. The function should return a pointer to the new array. Demonstrate the
function in a complete program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int &, int);
void reverseSSort(int *, int);

int main() {

    int numbers,
        amount,
        count;

    int *integers = nullptr;

    cout << "How many numbers do you wish to put into the array? ";
    cin >> amount;

    integers = new int[amount];

    cout << "Enter the numbers below:" << endl;
    for (count = 0; count < amount; count++) {
        cout << "Number #" << (count + 1) << ": ";
        integers[count] = checker(*(integers + count), 0);
    }    

    reverseSSort(integers, amount);
    cout << "Displaying the contents of the sorted array: ";
    for (int i = 0; i < amount; i++) {
        cout << *(integers + i) << " ";
    }
    cout << endl;

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}


void reverseSSort(int *array, int size) {
    int startScan, maxIndex;
    int maxValue;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        maxIndex = startScan;
        maxValue = array[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (array[index] > maxValue) {
                maxValue = array[index];
                maxIndex = index;
            }
        }
        array[maxIndex] = array[startScan];
        array[startScan] = maxValue;
    }
}
