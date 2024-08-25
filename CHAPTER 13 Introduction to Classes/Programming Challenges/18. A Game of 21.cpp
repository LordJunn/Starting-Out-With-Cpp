/* For this assignment, you will write a program that lets the user play against the com-
puter in a variation of the popular blackjack card game. In this variation of the game,
two six-sided dice are used instead of cards. The dice are rolled, and the player tries to
beat the computer’s hidden total without going over 21.
Here are some suggestions for the game’s design:
• Each round of the game is performed as an iteration of a loop that repeats as long
as the player agrees to roll the dice, and the player’s total does not exceed 21.
• At the beginning of each round, the program will ask the users whether they want
to roll the dice to accumulate points.
• During each round, the program simulates the rolling of two six-sided dice. It rolls
the dice first for the computer, and then it asks the user if he or she wants to roll.
(Use the Die class that was demonstrated in this chapter to simulate the dice).
• The loop keeps a running total of both the computer and the user’s points.
• The computer’s total should remain hidden until the loop has finished.
• After the loop has finished, the computer’s total is revealed, and the player with the
most points without going over 21 wins. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
#include "Die.cpp"
using namespace std;

int main() {
    Die comp(6);
    Die player(6);
    const int max = 21;
    char choice = 'Y';

    int computer = 0;
    int play = 0;

    while(toupper(choice) == 'Y' && play <= 21  && computer <= 21) {
        comp.roll();
        computer += comp.getValue();

        cout << "The computer has rolled. Do you want to roll your dice? ";
        cin >> choice;
        if(toupper(choice) == 'Y') {
            player.roll();
            cout << "You rolled a " << player.getValue() << endl;
            play += player.getValue();
        }
        else {
            cout << "Skipping your turn. " << endl;
        }

        cout << "Would both of you like to roll more? ";
        cin >> choice;
    }

    if(computer < 21 && play < 21) {
        if(computer > play) {
            cout << "Computer win!" << endl;
        }
        else if (computer == play) {
            cout << "Tie!" << endl;
        }
        else {
            cout << "Player win!" << endl;
        }
    }
    else if(play > 21 && computer <= 21) {
        cout << "Player lost as you exceeded 21!" << endl;
    }
    else if(computer > 21 && play <= 21){
        cout << "Computer lost as it exceeded 21!" << endl;
    }
    else {
        cout << "Both loss as they exceeded 21. " << endl;
    }

    cout << "Computer value: " << computer << endl;
    cout << "Player value: " << play << endl;

    return 0;
}