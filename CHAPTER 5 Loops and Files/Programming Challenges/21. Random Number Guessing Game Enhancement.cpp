/* Enhance the program that you wrote for Programming Challenge 20 so it keeps a count
of the number of guesses that the user makes. When the user correctly guesses the ran-
dom number, the program should display the number of guesses. */

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
    
    int num, answer, 
        guesses = 1;
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

    guesses += 1;

    cout << "Let's try a new number." << endl;
    cin >> answer;

    }

    cout << "WIN!!" << endl;
    cout << "Total guesses: " << guesses << endl;

    return 0;
}