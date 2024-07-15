/* Write a function named coinToss that simulates the tossing of a coin. When you call
the function, it should generate a random number in the range of 1 through 2. If the
random number is 1, the function should display “heads.” If the random number is 2,
the function should display “tails.” Demonstrate the function in a program that asks
the user how many times the coin should be tossed and then simulates the tossing of
the coin that number of times. */

// stuff stolen from PC8 C5
// hmm doesnt seem like i can add a counter, at least guide didnt show

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For the time function
using namespace std;

void coinToss(int);
int valueCount(int);

int main() {

    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);    

    // Guh
    const int MIN_VALUE = 1,
              MAX_VALUE = 2;

    int value, toss, 
        headst = 0, 
        tailst = 0;

    cout << "How many throws do you want to do? ";
    cin >> toss;

    for (int i = 1; i <= toss; i++) {
        int heads = 0, tails = 0;
        value = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        coinToss(value);

        valueCount(value);
        headst += heads;
        tailst += tails;

    }    

    cout << headst << " " << tailst;



    return 0;
}

void coinToss(int value) {

    static int heads, tails;
    
    if (value == 1) {
        cout << "Heads." << endl;
        heads++;
    }
    else {
        cout << "Tails. " << endl;
        tails++;
    }

}

int valueCount(int value) {

    static int heads, tails;

    if (value == 1) {
        return heads;
    }
    else {
        return tails;
    }

}