/* Write a program that can be used to gather statistical data about the number of mov-
ies college students see in a month. The program should perform the following steps:
A) Ask the user how many students were surveyed. An array of integers with this
many elements should then be dynamically allocated.
B) Allow the user to enter the number of movies each student saw into the array.
C) Calculate and display the average, median, and mode of the values entered. (Use
the functions you wrote in Problems 8 and 9 to calculate the median and mode.)

Input Validation: Do not accept negative numbers for input. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int &, int);
double average(double, int);
void selectionSort(int *, int);
double determineMedian(int *, int);
double determineMode(int[], int);
void Mode(double);


int main() {

    int numbers,
        amount,
        count,
        mode,
        total = 0;
    double median,
           avg = 0;

    int *integers = nullptr;

    cout << "How many students were surveyed? ";
    cin >> amount;

    integers = new int[amount];

    cout << "Enter the numbers below:" << endl;
    for (count = 0; count < amount; count++) {
        cout << "Number of movies student #" << (count + 1) << " saw: ";
        integers[count] = checker(*(integers + count), 0);
        total += integers[count];
        //cout << total;
    }    

    selectionSort(integers, amount);
    cout << "Displaying the contents of the sorted array: ";
    for (int i = 0; i < amount; i++) {
        cout << *(integers + i) << " ";
    }
    cout << endl;

    avg = average(total, amount);
    cout << "Average movies viewed: " << avg << endl;

    median = determineMedian(integers, amount);
    cout << endl << "The median is " << median << ". " << endl;

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

double average(double total, int amount) {

    double avg = total/amount;
    //cout << total << amount;
    return avg;

}

void selectionSort(int *array, int size) {
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

double determineMedian(int *array, int size) {

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

        owo = (*(array + midA) + *(array + midB));
        owo /= 2;

    }

    return owo;
}

double determineMode(int array[], int SIZE) {

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

void Mode(double owo) {
    if(owo == -1) {
        cout << "No mode is found. " << endl;
    }
    else {
        cout << "The mode is " << owo << ". " << endl;
    }
}

