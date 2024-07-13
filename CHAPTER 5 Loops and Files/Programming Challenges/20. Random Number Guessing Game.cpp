/* Write a program that generates a random number and asks the user to guess what the
number is. If the user’s guess is higher than the random number, the program should
display “Too high, try again.” If the user’s guess is lower than the random number,
the program should display “Too low, try again.” The program should use a loop that
repeats until the user correctly guesses the random number. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>  // For rand and srand // stolen from PC8 C5
#include <ctime>    // For the time function
using namespace std;

int main() {
    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);    

    // Change it depends on difficulty
    const int MIN_VALUE = 1,
              MAX_VALUE = 9;
    
    int num, answer;
    int choice;

    num = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    cout << "Guess the number thats between " << MIN_VALUE << " and " << MAX_VALUE << "." << endl
        << "Key in your answer here." << endl;

    cin >> answer;

    while (answer != num) {

        if (answer < num) {
            cout << "Too small." << endl;
        }
        else {
            cout << "Too big." << endl;
        }

    cout << "Let's try a new number." << endl;
    cin >> answer;

    }

    cout << "WIN!!" << endl;

    return 0;
}