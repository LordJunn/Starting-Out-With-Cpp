/* Write a program that simulates a lottery. The program should have an array of five
integers named lottery and should generate a random number in the range of 0
through 9 for each element in the array. The user should enter five digits, which should
be stored in an integer array named user. The program is to compare the correspond-
ing elements in the two arrays and keep a count of the digits that match. For example,
the following shows the lottery array and the user array with sample numbers stored
in each. There are two matching digits (elements 2 and 4).
lottery array:
7 4 9 1 3
user array:
4 2 9 7 3
The program should display the random numbers stored in the lottery array and the
number of matching digits. If all of the digits match, display a message proclaiming the
user as a grand prize winner. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int digits = 5;

int lotto(int);
int checker(int&, int, int);
void getValues(int[]);
void compareValues(int[], int[]);
void showLotto(int[]);

int lottery[digits];
int user[digits];

int main() {

    for (int i = 0; i < digits; i++) {
        lottery[i] = lotto(i);
    }
 
    getValues(user);
    compareValues(lottery, user);

    return 0;
}

int lotto(int i) {

    int valueC; 

    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);    

    // Guh
    const int MIN_VALUE = 0,
              MAX_VALUE = 9; 

    valueC = ((rand() + i) % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
    return valueC;
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

void getValues(int array[]) {

    for(int col = 0; col < digits; col++) {

        cout << "Enter digit #" << (col + 1) << " for your lottery guess here. ";
        array[col] = checker(array[col], 0, 9);

    }

}

void compareValues(int a[], int b[]) {

    int c[digits], 
        match = 0;

    for(int col = 0; col < digits; col++) {

        if (a[col] == b[col]) {
            c[match] = a[col];          
            match++;
        }

    }
     
    if(match == digits) {
        cout << "Winner!!" << endl;
    }
    else if(match > 0) {
        cout << "You have matched a total of " << match << " digits." << endl;
        cout << "Here are the digits that matched: " << endl;

        for(int check = 0; check < match; check++) {

            if(check == (match - 1)) {
                cout << c[check] << ". ";
            }
            else {
                cout << c[check] << ", ";
            }   

        }
        cout << endl;
        showLotto(lottery);

    }
    else {
        cout << "There is no matched digits." << endl;
        showLotto(lottery);
    }
    
}

void showLotto(int a[]) {
    cout << "These were the winning numbers: ";
    for (int i = 0; i < digits; i++) {
        cout << a[i] << " ";
    }

}

