/* Morse code is a code where each letter of the English alphabet, each digit, and various
punctuation characters are represented by a series of dots and dashes. Table 10-9
shows part of the code.
Write a program that asks the user to enter a string, and then converts that string to
Morse code. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

string MorseCode(char c);
string converter(string&);

const char* characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.? ";
const char* morseCodes[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",   // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",        // S-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", // 0-9
    "--..--", ".-.-.-", "..--..", " "};  // Comma, Period, Question Mark, space 

int main() {

    string regular, MC;
    cout << "Enter a string to convert into Morse Code: ";
    getline(cin, regular);

    MC = converter(regular);
    cout << "Morse code = " << MC << endl;

    return 0;
}

// converts a single char
string MorseCode(char c) { 
    const int maxsize = sizeof(characters) - 1; // Exclude null terminator
    c = toupper(c); // Convert the character to uppercase

    // Find the character in the characters array
    const char* ptr = strchr(characters, c);

    // If the character is found, return its Morse code
    if(ptr != nullptr) {
        int index = ptr - characters; // Calculate the index of the character
        cout << c << " = " << morseCodes[index] << endl;
        return morseCodes[index];
    }
    else {
        return ""; // Return empty string for characters not in the array
    }
    
}

// repeats the above several times
string converter(string& input) { 
    string morse;

    for(char c : input) {  // for ( range_declaration : range_expression ) 
        morse += MorseCode(c) + " ";
    }
    return morse;
}

