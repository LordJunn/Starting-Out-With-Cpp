/* For this assignment, you will create a game program using the Coin class from
Programming Challenge 12. The program should have three instances of the Coin
class: one representing a quarter, one representing a dime, and one representing a nickel.
When the game begins, your starting balance is $0. During each round of the game,
the program will toss the simulated coins. When a coin is tossed, the value of the coin
is added to your balance if it lands heads-up. For example, if the quarter lands heads-
up, 25 cents is added to your balance. Nothing is added to your balance for coins that
land tails-up. The game is over when your balance reaches $1 or more. If your balance
is exactly $1, you win the game. You lose if your balance exceeds $1. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

class Coin{
   private:
    string sideUp;

   public:
    Coin() {
        // Initialize random seed
        srand(static_cast<unsigned int>(time(0)));
        // Randomly determine the side of the coin that is facing up
        toss();        
    }

    // Simulate the tossing of the coin
    void toss() {
        // Generate a random number between 0 and 1
        int randomNumber = rand() % 2;
        // Set the sideUp member variable accordingly
        sideUp = (randomNumber == 0) ? "heads" : "tails";

    }

    // Return the value of the sideUp member variable
    string getSideUp() {
        return sideUp;
    }    

};

int main() {

    Coin quarter, dime, nickel;
    int i = 0;

    double balance = 0.0;
    const double QUARTER_VALUE = 0.25,
                 DIME_VALUE = 0.10,
                 NICKEL_VALUE = 0.05;

    cout << "The quarter is initially facing " << quarter.getSideUp() << endl;
    cout << "The dime is initially facing " << dime.getSideUp() << endl;
    cout << "The nickel is initially facing " << nickel.getSideUp() << endl;

    cout << "Enter any key to start throwing.";
    cin.get();   

    int h = 0, t = 0;

    while(balance < 1.0) {
        quarter.toss();
        dime.toss();
        nickel.toss();

        cout << "Throw #" << (i + 1) << " stats: \n";
        cout << "Quarter: " << quarter.getSideUp() << ", Dime: " << dime.getSideUp() << ", Nickel: " << nickel.getSideUp() << endl;

        // Update balance based on the coins that landed heads-up
        if (quarter.getSideUp() == "heads") balance += QUARTER_VALUE;
        if (dime.getSideUp() == "heads") balance += DIME_VALUE;
        if (nickel.getSideUp() == "heads") balance += NICKEL_VALUE;

        // Increment counters for heads and tails
        if (quarter.getSideUp() == "heads") {
            h++;
        }
        else {
            t++;
        }
        if (dime.getSideUp() == "heads") {
            h++;
        }
        else {
            t++;
        }
        if (nickel.getSideUp() == "heads") {
            h++;
        }
        else {
            t++;
        }
        cout << fixed << setprecision(2) << "Current balance: $" << balance << endl;
    
    i++;
    }

    if(balance == 1.0) {
        cout << "You win! ";
    }
    else {
        cout << "You lost! ";
        balance -= 1;
        cout << "You overexceeded it by $" << balance << endl;
    }

    cout << "Total throws: " << (i * 3) << endl;
    cout << "Total heads: " << h << endl;
    cout << "Total tails: " << t << endl;

    return 0;
}