/* For this assignment, you will write a program that simulates a fishing game. In this
game, a six-sided die is rolled to determine what the user has caught. Each possible
item is worth a certain number of fishing points. The points will not be displayed until
the user has finished fishing, and then a message is displayed congratulating the user
depending on the number of fishing points gained.
Here are some suggestions for the game’s design:
• Each round of the game is performed as an iteration of a loop that repeats as long
as the player wants to fish for more items.
• At the beginning of each round, the program will ask the user whether he or she
wants to continue fishing.
• The program simulates the rolling of a six-sided die (use the Die class that was
demonstrated in this chapter).
• Each item that can be caught is represented by a number generated from the die. For
example, 1 for “a huge fish,” 2 for “an old shoe,” 3 for “a little fish,” and so on.
• Each item the user catches is worth a different amount of points.
• The loop keeps a running total of the user’s fishing points.
• After the loop has finished, the total number of fishing points is displayed, along
with a message that varies depending on the number of points earned. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
#include "Die.cpp" // ah so this works
using namespace std;

int main() { // stealing from 13-16

    const int DIE_SIDES = 6;
    int score = 0;
    int points = 0;
    int totalRolls = 0;
    Die die(DIE_SIDES);
    cout << "Getting die sides: " << die.getSides() << endl;

    char choice = 'Y';

    while(toupper(choice) == 'Y') {

        die.roll();
        totalRolls++;
        cout << "Die has rolled a " << die.getValue() << endl;
        int rollResult = die.getValue();

        // Assign points based on the roll result
        switch(rollResult) {
            case 1:
                points += 1; // Huge fish
                break;
            case 2:
                points += 2; // Old shoe
                break;
            case 3:
                points += 3; // Little fish
                break;
            case 4:
                points += 4; // Seaweed
                break;
            case 5:
                points += 5; // Jellyfish
                break;
            case 6:
                points += 6; // Treasure chest
                break;
            default:
                cout << "Huh?" << endl;
                break;
        }

        cout << "Do you want to continue fishing? ";
        cin >> choice;
    }

    cout << "Total fishing points: " << points << endl;
    cout << "Total rolls: " << totalRolls << endl;
    points = static_cast<double>(points);
    points /= static_cast<double>(totalRolls);
    
    if(points >= 5)
        cout << "Congratulations! You're a master fisher!" << endl;
    else if(points >= 2)
        cout << "Not bad! You're getting better at fishing!" << endl;
    else
        cout << "Keep practicing! You'll become a great fisher someday!" << endl;

    return 0;
}