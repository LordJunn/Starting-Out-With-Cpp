/* Write a function that accepts an int array and the array’s size as arguments. The
function should create a new array that is one element larger than the argument array.
The first element of the new array should be set to 0. Element 0 of the argument array
should be copied to element 1 of the new array, element 1 of the argument array should
be copied to element 2 of the new array, and so forth. The function should return a
pointer to the new array. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int &, int);
int *plusArraySize(int [], int);
void displayContent(int*, int);

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

    int *integers2 = plusArraySize(integers, amount);

    cout << "Displaying the contents of the array: ";
    displayContent(integers, amount);

    cout << "Displaying the contents of the array 2: ";
    displayContent(integers2, (amount + 1));

    delete[] integers2;
    integers2 = nullptr;

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

int *plusArraySize(int array[], int size) {
    
    const int plusOne = (size + 1);
    int *newArray = new int[plusOne];

    *(newArray) = 0;

    for (int i = 1; i < plusOne; i++)
    {
        *(newArray + i) = array[i - 1];
    }

    return newArray;  
}

void displayContent(int *array, int amount) {
    for (int i = 0; i < amount; i++) {
        cout << *(array + i) << " ";
    }
}

