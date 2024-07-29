/* Write a function that accepts either a pointer to a C-string, or a string object, as its
argument. The function should return the character that appears most frequently in the
string. Demonstrate the function in a complete program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

char determineMode(char*, int); // stolen from PC13 C9

int main() {

    char *line = nullptr;
    int SIZE, sum, largest, smallest;
    char frequent;

    cout << "What is the length of your string? ";
    cin >> SIZE;    

    line = new char[SIZE + 1];
    cout << "Input a string no more than " << (SIZE) << " in length. " << endl;
    cin.ignore();
    cin.getline(line, SIZE + 1);

    string str(line); // Convert char* to string

    frequent = determineMode(line, SIZE);
    cout << "The character that appeared most frequently is: " << frequent;


    return 0;
}

char determineMode(char *array, int SIZE) {

    
    int maxCount = 0;
    char maxChar = array[0];
    
    char owo, maxV;
        for (int i = 0; i < SIZE; i++) {

            if(isalpha(array[i])) {

                int count = 1;
                for (int j = i + 1; j < SIZE; j++) {

                    if(tolower(array[j]) == tolower(array[i])) {
                        //cout << " J = " << *(array + j); 
                        //cout << " I = " << *(array + i) << endl;
                        count++;
                    }
                }
            //cout << " Cunt = " << count;

            if (count > maxCount) {
                maxCount = count;
                //cout << " Count = " << count;
                maxChar = array[i];
                //cout << " Value = " << maxChar;
            }

            }



        }

    return maxChar;

}
