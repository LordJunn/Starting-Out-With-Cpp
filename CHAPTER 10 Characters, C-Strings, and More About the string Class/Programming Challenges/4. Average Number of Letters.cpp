/* Modify the program you wrote for Problem 3 (Word Counter), so it also displays the
average number of letters in each word. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int count(char*, int);
int count(string);
int wordCounter(char*, int);

int main() {

    char *line = nullptr;
    int SIZE;
    double length, counter;

    cout << "What is the length of your string? ";
    cin >> SIZE;    

    line = new char[SIZE + 1];
    cout << "Input a string no more than " << (SIZE) << " characters. " << endl;
    cin.ignore();
    cin.getline(line, SIZE + 1);

    string str(line); // Convert char* to string

    length = count(line, SIZE);
    cout << "The string's length (using char*) is: " << length << endl;

    length = count(line);
    cout << "The string's length (using string) is: " << length << endl;

    counter = wordCounter(line, SIZE);
    cout << "The average length of each word is: " << counter/length;

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

int count(string str) {
    int count = 0;
    string word;
    stringstream ss(str);

    while (ss >> word)
        count++;

    return count;
}

int wordCounter(char *array, int SIZE) {

    int owo;

    while (*array != '\0') {
        // Skip spaces
        while (*array == ' ') {
            array++;
        }
        while (*array != ' ' && *array != '\0') {
            array++;
            owo++;
        }
    }
    return owo;
}

