/* Write a program that reads a sentence as input and converts each word to “Pig Latin.”
In one version, to convert a word to Pig Latin you remove the first letter and place
that letter at the end of the word. Then you append the string “ay” to the word. Here
is an example:
English: I SLEPT MOST OF THE NIGHT
Pig Latin: IAY LEPTSAY OSTMAY FOAY HETAY IGHTNAY */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <sstream>
using namespace std;

int checker(int&, int, int);
string pig(string&);
string pigEX(string&);
string babification(const string&, int);

int main() {

    string sentence;  
    int choice; 

    cout << "\t\t oink oink \t" << endl;
    cout << "1) Removes the first letter and place that letter at the end of the word. " << endl;
    cout << "2) Similar to (1), but with an additional AY at the end of each word. " << endl;
    cout << "Which version would you like? ";
    choice = checker(choice, 1, 2);

    cin.ignore();
    cout << "Input a sentence to be translated to oink." << endl;
    getline(cin, sentence);

    string pigLatinSentence;

    pigLatinSentence = babification(sentence, choice);

    cout << pigLatinSentence;

    return 0;
}       

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

string pig(string& word) {

    string temp;

    if (word.empty()) {
        return ""; // Return empty string if input word is empty
    }
    else {   
        temp = word.substr(1);
        return temp + word[0]; // Move the first letter to the end
    }

}

string pigEX(string& word) {

    string temp;

    if (word.empty()) {
        return ""; // Return empty string if input word is empty
    }
    else {   
        //cout << "aaaaaaaaa";
        temp = word.substr(1);
        return temp + word[0] + "AY"; // Move the first letter to the end and append "ay"
    }

}

string babification(const string& sentence, int choice) {
    stringstream ss(sentence);
    string word, pigLatinSentence;

    if (choice == 1) {
        while (ss >> word) {
            pigLatinSentence += pig(word) + " "; // Convert each word to Pig Latin and append to the result
        }        
    }
    else {
        while (ss >> word) {
            pigLatinSentence += pigEX(word) + " "; // Convert each word to Pig Latin and append to the result
        }                
    }



    return pigLatinSentence;
}

