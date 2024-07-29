/* Write a function that returns an integer and accepts a pointer to a C-string as an argu-
ment. The function should count the number of characters in the string and return that
number. Demonstrate the function in a simple program that asks the user to input a
string, passes it to the function, and then displays the function’s return value. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int count(char*, int);

int main() {

    char *line = nullptr;
    int SIZE, length;

    cout << "What is the length of your string? ";
    cin >> SIZE;    

    line = new char[SIZE + 1];
    cout << "Input a string no more than " << (SIZE) << " characters. " << endl;
    cin >> line;

    length = count(line, SIZE);

    cout << "The string's length is: " << length;

    return 0;
}

int count(char *array, int SIZE) {

    int count = 0;

    while(*array != '\0') {
        count++;
        array++;
    }

    return count;

}