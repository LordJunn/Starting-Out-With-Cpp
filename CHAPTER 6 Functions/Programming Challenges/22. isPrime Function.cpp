/* A prime number is a number that is only evenly divisible by itself and 1. For example,
the number 5 is prime because it can only be evenly divided by 1 and 5. The number 6,
however, is not prime because it can be divided evenly by 1, 2, 3, and 6.
Write a function name isPrime, which takes an integer as an argument and returns
true if the argument is a prime number, or false otherwise. Demonstrate the function
in a complete program.

TIP: Recall that the % operator divides one number by another, and returns the
remainder of the division. In an expression such as num1 % num2, the % operator will
return 0 if num1 is evenly divisible by num2. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int);
int isPrime(int, int);

int main() {

    int num, checking, remainder;

    cout << "Enter a number to check if it is a prime number: ";
    num = checker(num, 0);

    for (int i = 1; i <= num; i++) {
        remainder = isPrime(num, i);
        checking += remainder;
    }

    if (checking > 2) {
        cout << "It is not a prime number." << endl;
    }
    else {
        cout << "It is a prime number." << endl;
    }

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin >> x;
    }

    return x;

}

int isPrime(int n, int i) {

    int remainder;

    remainder = (n % i);

    if (remainder != 0) {
        remainder = 0;
        return remainder;
    }
    else {
        remainder = 1;
        return remainder;
    }

}