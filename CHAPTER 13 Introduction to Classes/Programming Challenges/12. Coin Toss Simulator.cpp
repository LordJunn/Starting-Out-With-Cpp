/* Write a class named Coin. The Coin class should have the following member variable:
• A string named sideUp. The sideUp member variable will hold either “heads” or
“tails” indicating the side of the coin that is facing up.
The Coin class should have the following member functions:
• A default constructor that randomly determines the side of the coin that is facing up
(“heads” or “tails”) and initializes the sideUp member variable accordingly.
• A void member function named toss that simulates the tossing of the coin. When
the toss member function is called, it randomly determines the side of the coin that
is facing up (“heads” or “tails”) and sets the sideUp member variable accordingly.
• A member function named getSideUp that returns the value of the sideUp member
variable.
Write a program that demonstrates the Coin class. The program should create an
instance of the class and display the side that is initially facing up. Then, use a loop
to toss the coin 20 times. Each time the coin is tossed, display the side that is facing
up. The program should keep count of the number of times heads is facing up and the
number of times tails is facing up, and display those values after the loop finishes. */

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

    Coin syiling;
    int maxThrows;

    cout << "The coin is initially facing " << syiling.getSideUp() << endl;
    cout << "How many throws would you like? ";
    cin >> maxThrows;

    int h = 0, t = 0;

    for(int i = 0; i < maxThrows; i++) {
        syiling.toss();
        cout << "After toss #" << (i + 1) << ", the coin is now facing " << syiling.getSideUp() << endl;

        if(syiling.getSideUp() == "heads") {
            h++;
        }
        else {
            t++;
        }

    }

    cout << "Total throws: " << maxThrows << endl;
    cout << "Total heads: " << h << endl;
    cout << "Total tails: " << t << endl;

    return 0;
}