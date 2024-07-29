/* Write a function that accepts a pointer to a C-string as an argument and capitalizes
the first character of each sentence in the string. For instance, if the string argument
is “hello. my name is Joe. what is your name?” the function should manipu-
late the string so it contains “Hello. My name is Joe. What is your name?”
Demonstrate the function in a program that asks the user to input a string and then
passes it to the function. The modified string should be displayed on the screen.
Optional Exercise: Write an overloaded version of this function that accepts a string
class object as its argument. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

void capitalizeSentences(char*);
void capitalizeSentences(string&);

int main() {

    char *line = nullptr;
    int SIZE;

    cout << "What is the length of your string? ";
    cin >> SIZE;    

    cin.ignore();       

    line = new char[SIZE + 1];
    cout << "Input a string no more than " << (SIZE) << " characters. " << endl;
    cin.getline(line, SIZE + 1);

    capitalizeSentences(line);
    cout << "This is the capitalised sentence using char*: " << line << endl;

    string str(line);

    capitalizeSentences(str);
    cout << "This is the capitalised sentence using string&: " << line << endl;

    return 0;
}

void capitalizeSentences(char* str) {
    bool NewSentence = true;

    // Iterate through the C-string
    for (int i = -1; str[i] != '\0'; i++) {
        // Capitalize the first character of each sentence
        if (NewSentence && isalpha(str[i])) {
            str[i] = toupper(str[i]); // Capitalize the character
            NewSentence = false; // Reset the flag
        }
        // Check for sentence boundaries
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            NewSentence = true; // Set flag for the next character
        }
    }
}

void capitalizeSentences(string& str) {
    bool NewSentence = true;

    // Iterate through the C-string
    for (int i = -1; str[i] != '\0'; i++) {
        // Capitalize the first character of each sentence
        if (NewSentence && isalpha(str[i])) {
            str[i] = toupper(str[i]); // Capitalize the character
            NewSentence = false; // Reset the flag
        }
        // Check for sentence boundaries
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            NewSentence = true; // Set flag for the next character
        }
    }
}


