/* Write a function that accepts an int array and the array’s size as arguments. The func-
tion should create a new array that is twice the size of the argument array. The func-
tion should copy the contents of the argument array to the new array and initialize the
unused elements of the second array with 0. The function should return a pointer to
the new array. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int &, int);
int *doubleArraySize(int [], int);
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

    int *integers2 = doubleArraySize(integers, amount);

    cout << "Displaying the contents of the array: ";
    displayContent(integers, amount);

    cout << "Displaying the contents of the array 2: ";
    displayContent(integers2, (amount * 2));

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

int *doubleArraySize(int array[], int size) {
    
    const int twice = (size * 2);
    int *newArray = new int[twice];

    for (int i = 0; i < twice; i++)
    {
        if (i >= size)
            *(newArray + i) = 0;
        else
            *(newArray + i) = array[i];
    }

    return newArray;  
}

void displayContent(int *array, int amount) {
    for (int i = 0; i < amount; i++) {
        cout << *(array + i) << " ";
    }
}

