/* Write a program that can be used as a math tutor for a young student. The program
should display two random numbers to be added, such as
247 + 129 = 
The program should then pause while the student works on the problem. When the
student is ready to check the answer, he or she can press a key and the program will
display the correct solution:
247 + 129 = 376 */

#include <iostream>
#include <iomanip>
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
    
    int num1, num2, num;

    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    num = num1 + num2;

    cout << "What is " << num1 << " + " << num2 << " ?" << endl
         << "Press [Enter] to show the answer" << endl;

    cin.get();

    cout << "The answer is " << num << endl;

    return 0;
}