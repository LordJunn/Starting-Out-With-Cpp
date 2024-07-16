/* Write a program that allows two players to play a game of tic-tac-toe. Use a two-
dimensional char array with three rows and three columns as the game board. Each
element of the array should be initialized with an asterisk (*). The program should run
a loop that
• Displays the contents of the board array
• Allows player 1 to select a location on the board for an X. The program should ask
the user to enter the row and column number.
• Allows player 2 to select a location on the board for an O. The program should ask
the user to enter the row and column number.
• Determines whether a player has won, or a tie has occurred. If a player has won,
the program should declare that player the winner and end. If a tie has occurred, the
program should say so and end.
Player 1 wins when there are three Xs in a row on the game board. The Xs can appear
in a row, in a column, or diagonally across the board. A tie occurs when all of the
locations on the board are full, but there is no winner. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int ROWS = 3,
          COLUMNS = 3;

void displayBoard(char[][COLUMNS], int);
void displayBoard(char[][COLUMNS]);
int checker(int&, int, int);
void player(char[][COLUMNS], char);
bool checkByRow(char[][COLUMNS], char); // modified from PC8 C7 
bool checkByColumn(char[][COLUMNS], char); // modified from PC8 C7
bool checkByDiagonal1(char[][COLUMNS], char); // modified from PC8 C7
bool checkByDiagonal2(char[][COLUMNS], char); // see site
void determineWin(char[][COLUMNS], char);
void loser(char[][COLUMNS]);

char ticTacToe[ROWS][COLUMNS] = {{'*', '*', '*'},
                                 {'*', '*', '*'},
                                 {'*', '*', '*'}};

int main() {

    for (int i = 0; i < 4; i++) {
        displayBoard(ticTacToe, i);
        player(ticTacToe, 'X');
        determineWin(ticTacToe, 'X');
        player(ticTacToe, 'O');
        determineWin(ticTacToe, 'O');
    }
    loser(ticTacToe);
    displayBoard(ticTacToe);

    return 0;
}

void displayBoard(char array[][COLUMNS], int r) {

    cout << "This is how the board looks like in round " << r << endl;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void displayBoard(char array[][COLUMNS]) {

    cout << "This is how the board looked like when the game ended." << endl;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int checker(int &x, int i, int j) {

    char owo;

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void player(char array[][COLUMNS], char let) {

    cout << "It's time to place your " << let << " ." << endl;

    int row, col;
    bool occupied = false;

    do {

        cout << "Which row? ";
        row = checker(row, 1, 3);

        cout << "Which column? ";
        col = checker(col, 1, 3);

        if(array[(row-1)][(col-1)] == '*') {
            
            array[(row - 1)][(col - 1)] = let; 
            occupied = true;        
        }
        else {
            cout << "This place is occupied. " << endl;
            occupied = false;
        }

    }while (occupied == false);

}

bool checkByRow(char array[][COLUMNS], char w) {

    int test = 0;
    int sum, localArray[ROWS];
    localArray[0] = 0;

    for (int row = 0; row < ROWS; row++) {
        sum = 0;
        for (int col = 0; col < COLUMNS; col++) {

            if(array[row][col] == w) {
                sum++;
            }
        }
        localArray[row] = sum;
    }

    for (int check = 0; check < ROWS; check++) {

        if (localArray[check] == 3) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool checkByColumn(char array[][COLUMNS], char w) {

    int test = 0;
    int sum, localArray[ROWS];
    localArray[0] = 0;

    for (int col = 0; col < COLUMNS; col++) {
        sum = 0;       
        for (int row = 0; row < ROWS; row++) {

            if(array[row][col] == w) {
                sum++;
            }
        }
        localArray[col] = sum;
    }

    for (int col = 0; col < COLUMNS; col++) {

        if (localArray[col] == 3) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool checkByDiagonal1(char array[][COLUMNS], char w) {

    int test = 0;
    int sum, localArray[ROWS];
    localArray[0] = 0;

    for (int col = 0; col < COLUMNS; col++) {
        sum = 0;       
        for (int row = 0; row < ROWS; row++) {

            if(array[row][row] == w) {
                sum++;
            }
        }
        localArray[col] = sum;
    }

    for (int col = 0; col < COLUMNS; col++) {

        if (localArray[col] == 3) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool checkByDiagonal2(char array[][COLUMNS], char w) {

    int test = 0;
    int sum, localArray[ROWS];
    int diagonal;

    sum = 0; // array[2][0] == array[1][1] == array[0][2], aka 3-1, 2-2, 1-3

    for(int row = 0, column = (ROWS - 1); row < ROWS; row++, column--) { // huh so this is a thing

        if(array[row][column] == w) {
            sum++;
        }

    }

    if (sum == 3) {
        return true;
    }
    else {
        return false;
    }

}

void determineWin(char array[][COLUMNS], char let) {

    // was supposed to be a ton of ifs, until i tot of adding an else lose
    // that wasnt the best idea

    if(checkByRow(array, let) == 1) {
        cout << let << " won by row! ";
        displayBoard(array);
        exit(0);
    }
    else if(checkByColumn(array, let) == 1) {
        cout << let << " won by column! ";
        displayBoard(array);
        exit(0);
    }
    else if(checkByDiagonal1(array, let) == 1) {
        cout << let << " won diagonally! ";
        displayBoard(array);
        exit(0);
    }
    else if(checkByDiagonal2(array, let) == 1) {
        cout << let << " won diagonally! ";
        displayBoard(array);
        exit(0);
    }

}

void loser(char array[][COLUMNS]) {

    cout << "Seems like no one has won. ";

}

