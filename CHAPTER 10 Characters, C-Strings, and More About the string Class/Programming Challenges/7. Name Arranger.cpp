/* Write a program that asks for the user’s first, middle, and last names. The names
should be stored in three different character arrays. The program should then store,
in a fourth array, the name arranged in the following manner: the last name followed
by a comma and a space, followed by the first name and a space, followed by the
middle name. For example, if the user entered “Carol Lynn Smith”, it should store
“Smith, Carol Lynn” in the fourth array. Display the contents of the fourth array
on the screen */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

void namer(char*, const string&, int);
string combined(char*, char*, char*);

int main() {

int amount;

    char *firstN = nullptr,
           *middleN = nullptr, 
           *lastN = nullptr;

    string first, middle, last;

    cout << "How long is the name to be put in the array? ";
    cin >> amount;

    amount++;

    firstN = new char[amount];
    middleN = new char[amount];
    lastN = new char[amount];

    cin.ignore();
    namer(firstN, "first name", amount);
    namer(middleN, "middle name", amount);
    namer(lastN, "last name", amount); 

    first = combined(firstN, middleN, lastN);   

    cout << first;

    // Free allocated memory
    delete[] firstN;
    delete[] middleN;
    delete[] lastN;

    return 0;
}

void namer(char* owo, const string& anything, int amount) {

    char uwu;    
    cout << "Enter their " << anything << " here: ";
    cin.getline(owo, amount);

    // Validate the length of the input string
    if (strlen(owo) > amount - 1) {
        cout << "Input too long. Please enter a name with at most " << amount - 1 << " characters." << endl;
        // Clear the buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Prompt user again
        namer(owo, anything, amount);
    }

}

string combined(char* first, char* middle, char* last) {
    string result;
    result += last;         // Append last name
    result += ", ";         // Append comma and space
    result += first;        // Append first name
    result += " ";          // Append space
    result += middle;       // Append middle name
    return result;
}
