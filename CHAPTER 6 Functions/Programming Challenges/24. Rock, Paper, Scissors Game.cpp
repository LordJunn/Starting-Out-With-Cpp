/* Write a program that lets the user play the game of Rock, Paper, Scissors against the
computer. The program should work as follows.
1. When the program begins, a random number in the range of 1 through 3 is gener-
ated. If the number is 1, then the computer has chosen rock. If the number is 2, then
the computer has chosen paper. If the number is 3, then the computer has chosen
scissors. (Don’t display the computer’s choice yet.)
2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard.
(You can use a menu if you prefer.)
3. The computer’s choice is displayed.
4. A winner is selected according to the following rules:
• If one player chooses rock and the other player chooses scissors, then rock wins.
(The rock smashes the scissors.)
• If one player chooses scissors and the other player chooses paper, then scissors
wins. (Scissors cuts paper.)
• If one player chooses paper and the other player chooses rock, then paper wins.
(Paper wraps rock.)
• If both players make the same choice, the game must be played again to deter-
mine the winner.
Be sure to divide the program into functions that perform each major task. */

// stuff stolen from PC8 C6

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For the time function
using namespace std;

int checker(int&, int, int);
int computer(int);
void winner(int, int);

int main() {

    int user, choiceC, choiceU, output;

    cout << "Remember, 1 for rock, 2 for paper, 3 for scissors." << endl << endl;

    cout << "The computer is choosing its move..." << endl;
    choiceC = computer(1);

    cout << "Now, choose your move. ";
    choiceU = checker(user, 0, 4);
    
    winner(choiceC, choiceU);

    return 0;
}

int computer(int) {

    int valueC; 

    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);    

    // Guh
    const int MIN_VALUE = 1,
              MAX_VALUE = 3; 

    valueC = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
    return valueC;
}

int checker(int &x, int i, int j) {

    cin >> x;
    while ((x <= i ) || (x >= j)) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << ". ";
        cin >> x;
    }

    return x;

}

void winner(int c, int u) {
    if (c == u) {
        cout << "It's a tie!" << endl;
    }
    else if ((c == 1) && (u == 3)) { 
        cout << "You have chosen, scissors." << endl;
        cout << "Computer chose rock, it wins!" << endl;
    }
    else if ((c == 1) && (u == 2)) { 
        cout << "You have chosen, paper." << endl;
        cout << "Computer chose rock, you win!" << endl;
    }
    else if ((c == 2) && (u == 3)) { 
        cout << "You have chosen, scissors." << endl;
        cout << "Computer chose paper, you win!" << endl;
    }
    else if ((c == 2) && (u == 1)) { 
        cout << "You have chosen, rock." << endl;
        cout << "Computer chose paper, it wins!" << endl;
    }
    else if ((c == 3) && (u == 1)) { 
        cout << "You have chosen, rock." << endl;
        cout << "Computer chose scissors, you win!" << endl;
    }
    else if ((c == 3) && (u == 2)) { 
        cout << "You have chosen, paper." << endl;
        cout << "Computer chose scissors, it wins!" << endl;
    }
}