/* In statistics, the mode of a set of values is the value that occurs most often or with the
greatest frequency. Write a function that accepts as arguments the following:
A) An array of integers
B) An integer that indicates the number of elements in the array
The function should determine the mode of the array. That is, it should determine
which value in the array occurs most often. The mode is the value the function should
return. If the array has no mode (none of the values occur more than once), the func-
tion should return −1. (Assume the array will always contain nonnegative values.)
Demonstrate your pointer prowess by using pointer notation instead of array notation
in this function. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int &, int);
int determineMode(int[], int);
void Mode(int);

int main() {

    int *integers = nullptr,
        numbers,
        amount,
        count,
        mode;

    cout << "How many numbers do you wish to put into the array? ";
    cin >> amount;

    integers = new int[amount];

    cout << "Enter the numbers below:" << endl;
    for (count = 0; count < amount; count++) {
        cout << "Number #" << (count + 1) << ": ";
        integers[count] = checker(*(integers + count), 0);
    }    

    mode = determineMode(integers, amount);
    Mode(mode);


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

int determineMode(int array[], int SIZE) {

    int maxV = 0,
        maxC = 0,
        i, j;

    for (i = 0; i < SIZE; i++) {

        int count = 0;

        for (j = 0; j < SIZE; j++) {

            if(*(array + j) == *(array + i)) {
                //cout << " J = " << *(array + j); 
                //cout << " I = " << *(array + i) << endl;
                count++;
            }
        }
        //cout << " Cunt = " << count;

        if (count > maxC) {
            maxC = count;
            //cout << " Count = " << count;
            maxV = *(array + i);
            //cout << " Value = " << maxV;
        }

    }
    //cout << "Maxc = " << maxC << endl;

    if (maxC == 1) {
        //cout << " Whr value";
        maxV = -1;
    }

    return maxV;

}

void Mode(int owo) {
    if(owo == -1) {
        cout << "No mode is found. " << endl;
    }
    else {
        cout << "The mode is " << owo << ". " << endl;
    }
}

