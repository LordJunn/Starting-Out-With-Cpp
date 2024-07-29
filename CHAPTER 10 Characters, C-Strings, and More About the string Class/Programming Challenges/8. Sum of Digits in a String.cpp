/* Write a program that asks the user to enter a series of single digit numbers with nothing
separating them. Read the input as a C-string or a string object. The program should
display the sum of all the single-digit numbers in the string. For example, if the user
enters 2514, the program should display 12, which is the sum of 2, 5, 1, and 4. The
program should also display the highest and lowest digits in the string. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

int count(char*, int);
int highest(char*, int);
int lowest(char*, int);

int main() {

    char *line = nullptr;
    int SIZE, sum, largest, smallest;

    cout << "What is the length of your string? ";
    cin >> SIZE;    

    line = new char[SIZE + 1];
    cout << "Input a string no more than " << (SIZE) << " digits. " << endl;
    cin.ignore();
    cin.getline(line, SIZE + 1);

    string str(line); // Convert char* to string

    sum = count(line, SIZE);
    largest = highest(line, SIZE);
    smallest = lowest(line, SIZE);

    cout << "The sum of all the digits is: " << sum << endl;
    cout << "The highest digit in the string is: " << largest << endl;
    cout << "The smallest digit in the string is: " << smallest << endl;

    return 0;
}

int count(char *array, int SIZE) {

    int total = 0;

    while(*array != '\0') {

        if(isdigit(*array)) {
            total += *array - '0';
        }
        array++;
    }

    return total;

}

int highest(char *array, int SIZE) {

    int highest = (*array - '0');

    while(*array != '\0') {

        if(isdigit(*array)) {

            if((*array - '0') > highest) {
                highest = *array - '0';
            }

        }
        array++;
    }

    return highest;

}

int lowest(char *array, int SIZE) {

    int lowest = (*array - '0');

    while(*array != '\0') {

        if(isdigit(*array)) {

            if((*array - '0') < lowest) {
                lowest = *array - '0';
            }

        }
        array++;
    }

    return lowest;

}
