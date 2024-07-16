/* In a program, write a function that accepts three arguments: an array, the size of the
array, and a number n . Assume that the array contains integers. The function should
display all of the numbers in the array that are greater than the number n  */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int); 
int greaterThanN(const int[], int, int);

int main() {

    const int size = 10; // change when necessary
    int numbers[size];
    int n, greater;

    for (int i = 0; i < size; i++) {
        cout << "Enter an integer for array #" << (i + 1) << endl;
        numbers[i] = checker(numbers[i], numbers[i - 1]); // somehow i cant enter smaller than 1 (bigger than 0)
    }

    cout << "Enter a number you want to find that is greater than. ";
    cin >> n;
    cout << endl;

    greater = greaterThanN(numbers, size, n);
    if (greater > 0) {
        cout << "The list of numbers bigger than " << n << " are: " << endl;
        cout << endl;
        cout << "There are a total of " << greater << " numbers bigger than " << n << "." << endl;    
    }
    else {
        cout << "There are no numbers bigger than " << n << "." << endl;
    }

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}


int greaterThanN(const int array[], int size, int n) {

    int greater = 0;
    for (int i = 0; i < size; i++) {

        if (array[i] > n) {

            if (i == size - 1) {
                cout << array[i];
                greater++;            
            }
            else {
                cout << array[i] << ", ";
                greater++;            
            }
        }

    }
    return greater;
}