/* Write a function that accepts a pointer to a C-string as an argument and returns the
number of words contained in the string. For instance, if the string argument is “Four
score and seven years ago” the function should return the number 6. Demonstrate the
function in a program that asks the user to input a string and then passes it to the func-
tion. The number of words in the string should be displayed on the screen. Optional
Exercise: Write an overloaded version of this function that accepts a string class object
as its argument. */

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
    cin.ignore();
    cin.getline(line, SIZE + 1);

    length = count(line, SIZE);

    cout << "The string's length is: " << length;

    return 0;
}

int count(char *array, int SIZE) {

    int count = 0;

    while (*array != '\0') {
        // Skip spaces
        while (*array == ' ')
            array++;
        if (*array != '\0') { // Ensure not at the end of the string
            count++; // Found a word // Skip to the end of the word
            while (*array != ' ' && *array != '\0')
                array++;
        }
    }

    return count;

}

