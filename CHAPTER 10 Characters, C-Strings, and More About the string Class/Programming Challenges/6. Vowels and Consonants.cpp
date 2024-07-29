/* Write a function that accepts a pointer to a C-string as its argument. The function
should count the number of vowels appearing in the string and return that number.
Write another function that accepts a pointer to a C-string as its argument. This func-
tion should count the number of consonants appearing in the string and return that
number.
Demonstrate these two functions in a program that performs the following steps:
1. The user is asked to enter a string.
2. The program displays the following menu:
A) Count the number of vowels in the string
B) Count the number of consonants in the string
C) Count both the vowels and consonants in the string
D) Enter another string
E) Exit the program
3. The program performs the operation selected by the user and repeats until the user
selects E to exit the program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

void menu(char);
void displayMenu();
void vowelCounter(char*);
void consonantCounter(char*);
void dualCounter(char*);
char* capitalize(char*);
char* stringger();

char* lineofwords;

int main() {

    char *line = nullptr;
    int SIZE, vowelC, constC;
    char owo = 'd';

    menu(owo);
    cout << "Exiting the program :D";

    return 0;
}

void menu(char owo) {

    while (toupper(owo) != 'E') {

        if (toupper(owo) == 'A') {
            lineofwords = capitalize(lineofwords); 
            vowelCounter(lineofwords);
        }
        else if (toupper(owo) == 'B') {
            lineofwords = capitalize(lineofwords); 
            consonantCounter(lineofwords);
        }
        else if (toupper(owo) == 'C') {
            lineofwords = capitalize(lineofwords); 
            dualCounter(lineofwords);
        }
        else if (toupper(owo) == 'D') {
            cout << "Hallo :D" << endl;
            lineofwords = stringger();
        }
        else {
            cout << "If you would like to continue, choose from the menu options, not those not from it. ";
            displayMenu();
            cin >> owo;
        }
        cout << "Current string: " << lineofwords << endl;
        displayMenu();
        cin >> owo;

    }

}

void displayMenu() {
    cout << endl;
    cout << "A) Count the number of vowels in the string" << endl;
    cout << "B) Count the number of consonants in the string" << endl;
    cout << "C) Count both the vowels and consonants in the string" << endl;
    cout << "D) Enter another string" << endl;
    cout << "E) Exit the program" << endl;
    cout << "Enter your choice: ";    
}

void vowelCounter(char* words) {
    cout << "Vowel :D" << endl;

    int count = 0;
    for (int i = 0; words[i] != '\0'; i++) {
        if (isalpha(words[i]) && strchr("AEIOU", words[i])) {
            count++;
        }
    }
    cout << "Number of consonants: " << count << endl;
}

void consonantCounter(char* words) {
    cout << "Consonant :D" << endl;

    int count = 0;
    for (int i = 0; words[i] != '\0'; i++) {
        if (isalpha(words[i]) && !strchr("AEIOU", words[i])) {
            count++;
        }
    }
    cout << "Number of consonants: " << count << endl;
}

void dualCounter(char* words) {
    cout << "Dual :D" << endl;   

    int count = 0; 
    for (int i = 0; words[i] != '\0'; i++) {
        if(isalpha(words[i])) {
            count++;
        }

    }
    cout << "Number of vowels and consonants: " << count << endl;

}

char* capitalize(char* str) {

    // Iterate through the C-string
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]); // Capitalize the character
    }
    return str;
}

char* stringger() {
    char *line = nullptr;
    int SIZE;

    cout << "What is the length of your string? ";
    cin >> SIZE;    

    cin.ignore();       

    line = new char[SIZE + 1];
    cout << "Input a char* no more than " << (SIZE) << " characters. " << endl;
    cin.getline(line, SIZE + 1);

    return line;
}

