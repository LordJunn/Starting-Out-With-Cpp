// This program demonstrates random numbers.
#include <cstdlib>  // For rand and srand
#include <ctime>    // For the time function
#include <iostream>
using namespace std;

int main() {
    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);

    // Display three random numbers.
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    return 0;
}