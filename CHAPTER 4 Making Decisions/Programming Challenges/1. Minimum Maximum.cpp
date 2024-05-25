/* Write a program that asks the user to enter two numbers. The program should use the
conditional operator to determine which number is the smaller and which is the larger. */

#include <iostream>
using namespace std;

int main() {

    int num1, num2;

    cout << "Enter your first number: " << endl;
    cin >> num1;
    cout << "Enter your second number: " << endl;
    cin >> num2;

    if (num1 > num2) {
        cout << "The first number is larger than the second number." << endl;
        cout << "The second number is smaller than the first number." << endl;           
    }
    else {
        cout << "The second number is larger than the first number." << endl; 
        cout << "The first number is smaller than the second number." << endl;       
    }
    return 0;
}