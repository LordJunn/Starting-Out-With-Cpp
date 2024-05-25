/* This is a modification of Programming Challenge 17 from Chapter 3. Write a program
that can be used as a math tutor for a young student. The program should display two
random numbers that are to be added, such as:
247 + 129
The program should wait for the student to enter the answer. If the answer is correct,
a message of congratulations should be printed. If the answer is incorrect, a message
should be printed showing the correct answer. */

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For the time function
using namespace std;

int main() {
    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);    

    // Const assuming max is 3 digit numbers
    const int MIN_VALUE = 100,
              MAX_VALUE = 999;
    
    int num1, num2, num, answer;

    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    num = num1 + num2;

    cout << "What is " << num1 << " + " << num2 << " ?" << endl
         << "Key in your answer here." << endl;

    cin >> answer;

    if ( num == answer) {
    cout << "Congratulations!" << endl;        
    }
    
    else {
    cout << "The answer is " << num << endl;
    }

    return 0;
}