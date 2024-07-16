/* The Lo Shu Magic Square is a grid with 3 rows and 3 columns shown in Figure 7-19.
The Lo Shu Magic Square has the following properties:
• The grid contains the numbers 1 through 9 exactly.
• The sum of each row, each column, and each diagonal all add up to the same
number. This is shown in Figure 7-20.
In a program you can simulate a magic square using a two-dimensional array. Write a
function that accepts a two-dimensional array as an argument, and determines whether
the array is a Lo Shu Magic Square. Test the function in a program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int ROWS = 3,
          COLUMNS = 3;

int checker(int&, int, int); // wtf a SUPER CHECKER
void getValues(int[][COLUMNS]); // how to check if a value is already entered
int checkByRow(int[][COLUMNS]);
int checkByColumn(int[][COLUMNS], int);
int checkDiagonal(int[][COLUMNS], int);

int main() {

    int magicSquare[ROWS][COLUMNS], test, sum1, sum2, sum3;

    getValues(magicSquare);
    cout << endl;

    sum1 = checkByRow(magicSquare);
    sum2 = checkByColumn(magicSquare, sum1);
    sum3 = checkDiagonal(magicSquare, sum2);
    cout << endl;

    if((sum1 == sum2) && (sum2 == sum3)) {
        cout << "Congratulations, the array is a Lo Shu Magic Square.";
    }

    return 0;
}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x <= i || x >= j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getValues(int array[][COLUMNS]) {

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {

            cout << "Enter number for row #" << (row + 1) <<  " and column #" << (col + 1) << " here. ";
            array[row][col] = checker(array[row][col], 0, 10);

        }
    }

}

int checkByRow(int array[][COLUMNS]) {

    int test = 0;
    int sum, localArray[ROWS];
    localArray[0] = 0;

    for (int row = 0; row < ROWS; row++) {

        sum = 0;       
        for (int col = 0; col < COLUMNS; col++) {
            sum += array[row][col];
        }
        localArray[row] = sum;
    }

    if ((localArray[0] == localArray[1]) && (localArray[0] == localArray[2])) {
        cout << "All rows are equal." << endl;
        return sum;
    }
    else {
        cout << "Grr! Rows aren't equal!" << endl;
        exit(0);
    }
}

int checkByColumn(int array[][COLUMNS], int num) {

    int test = 0;
    int sum, localArray[ROWS];
    localArray[0] = 0;

    for (int col = 0; col < COLUMNS; col++) {

        sum = 0;       
        for (int row = 0; row < ROWS; row++) {
            sum += array[row][col];
        }
        localArray[col] = sum;
    }

    if ((localArray[0] == num) && (localArray[0] == localArray[1]) && (localArray[0] == localArray[2])) {
        cout << "All columns are equal." << endl;
        return sum;
    }
    else {
        cout << "Grr! Columns aren't equal!" << endl;
        exit(0);
    }
}

int checkDiagonal(int array[][COLUMNS], int num) {
    
    int sumA, sumB;
    sumA = array[0][0] + array[1][1] + array[2][2];
    sumB = array[2][0] + array[1][1] + array[0][2];


    if ((sumA == num) && (sumB == num)) {
        cout << "All diagonals are equal.";

    } 
    else {
        cout << "Grr! Diagonals aren't equal!" << endl;
        exit(0);
    }
    return sumA;    

}
