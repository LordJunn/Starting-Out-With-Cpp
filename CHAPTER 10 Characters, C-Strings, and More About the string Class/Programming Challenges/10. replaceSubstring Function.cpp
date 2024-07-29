/* Write a function named replaceSubstring. The function should accept three C-string
or string object arguments. Let’s call them string1, string2, and string3. It
should search string1 for all occurrences of string2. When it finds an occurrence of
string2, it should replace it with string3. For example, suppose the three arguments
have the following values:
string1: “the dog jumped over the fence”
string2: “the”
string3: “that”
With these three arguments, the function would return a string object with the value
“that dog jumped over that fence.” Demonstrate the function in a complete program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

void linefunction(char*, int);
void replacer(char*, char*, char*);

int main() {

    char *line1, *line2, *line3, *line4 = nullptr;
    int SIZE, sum, largest, smallest;
    char frequent;

    cout << "What is the length of your string? ";
    cin >> SIZE;   

    line1 = new char[SIZE + 1];
    line2 = new char[SIZE + 1];
    line3 = new char[SIZE + 1];

    cin.ignore();
    linefunction(line1, SIZE);
    linefunction(line2, SIZE);    
    linefunction(line3, SIZE);

    replacer(line1, line2, line3);

    cout << line1 << endl;

    return 0;
}

void linefunction(char* array, int SIZE) {
    cout << "Input a string no more than " << (SIZE) << " in length. " << endl;
    cin.getline(array, SIZE + 1);
}

void replacer(char* s1, char* s2, char* s3) {
    int s1L = strlen(s1); 
    int s2L = strlen(s2);
    int s3L = strlen(s3); // string n length 

    char* comparing = s1;
    int i;

    while((comparing == strstr(comparing, s2)) != 0) {
        
    // too lazy to write long might as well do this
    int comparer = s1L - (comparing - s1) - s2L;
    char* victim = (comparing + s3L + comparer);
    char* wontbechanged = (comparing + s2L  + comparer);

        for(int i = 0; i <= comparer; ++i) {
            *(victim - i) = *(wontbechanged - i);
        }
        for (int i = 0; i < s3L; ++i) {
            *(comparing + i) = s3[i];
        }
    }
    comparing += s3L;
}