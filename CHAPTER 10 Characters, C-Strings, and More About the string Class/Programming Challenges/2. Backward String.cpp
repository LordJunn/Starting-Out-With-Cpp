/* Write a function that accepts a pointer to a C-string as an argument and displays its
contents backward. For instance, if the string argument is “Gravity” the function
should display “ytivarG”. Demonstrate the function in a program that asks the user
to input a string and then passes it to the function. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void reverseStr(char *, int);

int main() {

    char *line = nullptr;
    int SIZE, length;

    cout << "What is the length of your string? ";
    cin >> SIZE;    

    line = new char[SIZE + 1];
    cout << "Input a string no more than " << (SIZE) << " characters. " << endl;
    cin >> line;

    reverseStr(line, SIZE);

    return 0;
}

void reverseStr(char *array, int SIZE) {

    char start = *(array + 0);

    int count = SIZE;
    while(*(array + count) != start) {
        count--;
        cout << array[count];
    }


}