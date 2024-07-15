/* Use the isPrime function that you wrote in Programming Challenge 22 in a program
that stores a list of all the prime numbers from 1 through 100 in a file. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream> // stolen from PC19 C6
using namespace std;

int checker(int&, int);
int isPrime(int, int);

int main() {

    int num, checking, remainder;

    num = 100; 

    ofstream output_file; 

    output_file.open("Prime Number List.txt");
    output_file << "Below is a list of all the prime numbers from 1 through 100." << endl;

    for (int i = 1; i <= num; i++) {

        for (int j = 1; j <= i; j++) {
            remainder = isPrime(i, j);
            checking += remainder;
        }

        if (checking > 2) {
            cout << i << " is not a prime number." << endl;
        }
        else {
            cout << i << " is a prime number." << endl;
            output_file << i << endl;
        }
        checking = 0;
    }

    output_file.close();


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