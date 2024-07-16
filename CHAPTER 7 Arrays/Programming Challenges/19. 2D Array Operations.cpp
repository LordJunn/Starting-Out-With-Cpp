/* Write a program that creates a two-dimensional array initialized with test data. Use any
data type you wish. The program should have the following functions:
• getTotal. This function should accept a two-dimensional array as its argument and
return the total of all the values in the array.
• getAverage. This function should accept a two-dimensional array as its argument
and return the average of all the values in the array.
• getRowTotal. This function should accept a two-dimensional array as its first argu-
ment and an integer as its second argument. The second argument should be the
subscript of a row in the array. The function should return the total of the values in
the specified row.
• getColumnTotal. This function should accept a two-dimensional array as its first
argument and an integer as its second argument. The second argument should be the
subscript of a column in the array. The function should return the total of the values
in the specified column.
• getHighestInRow. This function should accept a two-dimensional array as its first
argument and an integer as its second argument. The second argument should be the
subscript of a row in the array. The function should return the highest value in the
specified row of the array.
• getLowestInRow. This function should accept a two-dimensional array as its first
argument and an integer as its second argument. The second argument should be the
subscript of a row in the array. The function should return the lowest value in the
specified row of the array.
Demonstrate each of the functions in this program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int ROWS = 5,
          COLUMNS = 5;

int getTotal(int[][COLUMNS]);
int getAverage(int[][COLUMNS]);
int getRowTotal(int[][COLUMNS], int);
int getColumnTotal(int[][COLUMNS], int);
int getHighestInRow(int[][COLUMNS], int);
int getLowestInRow(int[][COLUMNS], int);

int total, average, uwu;

int PC19C7[ROWS][COLUMNS] = {{1, 2, 3, 4, 5}, 
                             {6, 7, 8, 9, 10}, 
                             {11, 12, 13, 14, 15},
                             {16, 17, 18, 19, 20},
                             {21, 22, 23, 24, 25}};

int main() {

    int a, b, c, d, e, f; // i mean i would make a menu but am too lazy

    a = getTotal(PC19C7);
    cout << a;
    b = getAverage(PC19C7);
    cout << b;
    c = getRowTotal(PC19C7, uwu);
    cout << c;
    d = getColumnTotal(PC19C7, uwu);
    cout << d;
    e = getHighestInRow(PC19C7, uwu);
    cout << e;
    f = getLowestInRow(PC19C7, uwu);
    cout << f;

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

int getTotal(int array[][COLUMNS]) {

    total = 0;
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            total += array[row][col];
        }
    }
    cout << endl;
    return total;

}

int getAverage(int array[][COLUMNS]) {

    average = 0;
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            average += array[row][col];
        }
    }
    cout << endl;
    average /= (ROWS*COLUMNS);

    return average;

}

int getRowTotal(int array[][COLUMNS], int owo) {

    cout << endl;
    cout << "Which row's total would you like? ";
    owo = checker(owo, 0, ROWS);
    total = 0;
    for(int col = 0; col < COLUMNS; col++) {
        total += array[(owo-1)][col];
    }

    return total;

}

int getColumnTotal(int array[][COLUMNS], int owo) {

    cout << endl;
    cout << "Which columns's total would you like? ";
    owo = checker(owo, 0, COLUMNS);
    total = 0;
    for(int row = 0; row < ROWS; row++) {
        total += array[row][(owo-1)];
    }

    return total;

}

int getHighestInRow(int array[][COLUMNS], int owo) {

    int highest;

    cout << endl;
    cout << "Which row's highest would you like? ";
    owo = checker(owo, 0, ROWS);
    highest = 0;

    highest = array[(owo-1)][0];

    for(int col = 1; col < COLUMNS; col++) {

        if ((array[(owo-1)][col]) > highest) {
            highest = array[(owo-1)][col];
        }
        
    }

    return highest;

}

int getLowestInRow(int array[][COLUMNS], int owo) {

    int lowest;

    cout << endl;
    cout << "Which row's lowest would you like? ";
    owo = checker(owo, 0, ROWS);
    lowest = 0;

    lowest = array[(owo-1)][0];

    for(int col = 1; col < COLUMNS; col++) {

        if ((array[(owo-1)][col]) < lowest) {
            lowest = array[(owo-1)][col];
        }
        
    }

    return lowest;

}

