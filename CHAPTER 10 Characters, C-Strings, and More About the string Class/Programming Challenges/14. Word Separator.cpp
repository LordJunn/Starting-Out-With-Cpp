/* Write a program that accepts as input a sentence in which all of the words are run
together, but the first character of each word is uppercase. Convert the sentence to a
string in which the words are separated by spaces and only the first word starts with
an uppercase letter. For example the string “StopAndSmellTheRoses.” would be con-
verted to “Stop and smell the roses. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

void capitalizeSentences(char*);

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
    cout << line;

    delete[] line;

    return 0;
}

void capitalizeSentences(char* str) {
    bool newWord = true;
    int length = strlen(str);

    // Iterate through the C-string
    for (int i = 0; str[i] != '\0'; i++) {
        if (newWord && isalpha(str[i])) {
            // If it's the beginning of a new word and it's not the first character of the string,
            // convert the first character of the word to lowercase
            if (i > 0) {
                //cout << str[i] << endl;
                str[i] = tolower(str[i]);
            }
            newWord = false; // Reset the flag
        }
        // Check for word boundaries
        else if (isupper(str[i])) {
            // If it's an uppercase letter and it's not the first character of the string,
            // insert a space before it to separate words
            if (i > 0) {
                //cout << i << " " << str[i] << " " ;
                
                char* temp = new char[length - i + 2]; // +2 to include space and null terminator
                strcpy(temp, str + i); // Copy the substring starting from i to temp
                str[i] = ' '; // Insert a space
                str[i + 1] = '\0'; // Null terminate

                //cout << temp << " " << str << endl;

                strcat(str, temp); // Concatenate the original string with the temp string
                delete[] temp; // Free the dynamically allocated memory
                length = strlen(str); // Update length after concatenation
            }
            newWord = true; // Set flag for the next character
        }
    }
}


