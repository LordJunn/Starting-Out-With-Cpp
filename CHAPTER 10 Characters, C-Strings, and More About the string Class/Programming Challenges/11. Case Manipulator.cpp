/* Write a program with three functions: upper, lower, and reverse. The upper function
should accept a pointer to a C-string as an argument. It should step through each char-
acter in the string, converting it to uppercase. The lower function, too, should accept a
pointer to a C-string as an argument. It should step through each character in the string,
converting it to lowercase. Like upper and lower, reverse should also accept a pointer
to a string. As it steps through the string, it should test each character to determine
whether it is upper- or lowercase. If a character is uppercase, it should be converted to
lowercase. Likewise, if a character is lowercase, it should be converted to uppercase.
Test the functions by asking for a string in function main, then passing it to them in
the following order: reverse, lower, and upper. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

void linefunction(char*, int);
void reverse(char*);
void upper(char*);
void lower(char*);

int main() {

    char *line = nullptr;
    int SIZE;

    cout << "What is the length of your string? ";
    cin >> SIZE;  

    line = new char[SIZE + 1];

    cin.ignore();
    linefunction(line, SIZE); 

    cout << "This is how your line looks like originally: " << line << endl;

    reverse(line);
    cout << "This is how your line looks like if we reverse the capitalization of the letters: " << line << endl;   

    upper(line);
    cout << "This is how your line looks like if we convert all the letters into uppercase: " << line << endl;

    lower(line);
    cout << "This is how your line looks like if we convert all the letters into lowercase: " << line << endl;

    return 0;
}

void linefunction(char* array, int SIZE) {
    cout << "Input a string no more than " << (SIZE) << " in length. " << endl;
    cin.getline(array, SIZE + 1);
}

void reverse(char* str) {

    // Iterate through the C-string
    for (int i = -1; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if(islower(str[i])) {
                str[i] = toupper(str[i]); // Capitalize the character
            }
            else if(isupper(str[i])) {
                str[i] = tolower(str[i]); // Lower the character
            }
            
        }
    }

}

void upper(char* str) {

    // Iterate through the C-string
    for (int i = -1; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]); // Capitalize the character
        }
    }
}

void lower(char* str) {

    // Iterate through the C-string
    for (int i = -1; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]); // Lower the character
        }
    }
}
