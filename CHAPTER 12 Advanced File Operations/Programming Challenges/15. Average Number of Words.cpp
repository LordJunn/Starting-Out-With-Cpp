/* If you have downloaded this book’s source code from the companion Web site, you
will find a file named text.txt in the Chapter 12 folder. (The companion Web site is
at www.pearsonhighered.com/gaddis.) The text that is in the file is stored as one sen-
tence per line. Write a program that reads the file’s contents and calculates the average
number of words per sentence. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

int main() { // suspiciously easy (i still gpted)

    string toread;

    cout << "File to read from? ";
    getline(cin, toread);

    ifstream file(toread);

    if(!file.is_open()) {
        cout << "File is not opened, the program will now kms.";
        return 1;
    }

    // Initialize variables to store total words and total sentences
    int totalwords = 0, sentences = 0;
    double avgwords = 0;

    // Read the file line by line
    string line;
    while(getline(file, line)) {
        // Increment the total number of sentences
        sentences++;

        // Count the number of words in the line
        int wordcounter = 0;
        bool eow = false; // end of word

        for(char ch : line) {

            if(isalpha(ch)) {
                // Found the beginning of a word
                if(!eow) {
                    eow = true;
                    wordcounter++;
                }

            }
            else {
                // Found non-alphabetic character, end of word
                eow = false;
            }

        }
        // Add the word count in the line to the total words
        totalwords += wordcounter; 
    }
    // Calculate the average number of words per sentence
    avgwords = static_cast<double>(totalwords)/sentences;

    cout << "Total words: " << totalwords << endl;
    cout << "Total sentences: " << sentences << endl;
    cout << "Average words per sentence: " << avgwords;

    return 0;
}