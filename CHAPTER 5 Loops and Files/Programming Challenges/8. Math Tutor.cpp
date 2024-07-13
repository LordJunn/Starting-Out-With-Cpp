/* This program started in Programming Challenge 15 of Chapter 3, and was modified
in Programming Challenge 9 of Chapter 4. Modify the program again so it displays a
menu allowing the user to select an addition, subtraction, multiplication, or division
problem. The final selection on the menu should let the user quit the program. After
the user has finished the math problem, the program should display the menu again.
This process is repeated until the user chooses to quit the program.

Input Validation: If the user selects an item not on the menu, display an error message
and display the menu again. */

// stuff stolen from PC9 C4.

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For the time function
using namespace std;

int main() {
    // Get the system time.
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);    

    // Const assuming max is 3 digit numbers
    const int MIN_VALUE = 100,
              MAX_VALUE = 999;
    
    int num1, num2, num, answer;
    int choice;

    do {

        cout << "Math tutor menu" << endl << endl;
        cout << "1. Addition\n"
             << "2. Subtraction\n"
             << "3. Multiplication\n"
             << "4. Division\n"
             << "5. Quit w\n"
             << "Enter your choice: ";
            
        cin >> choice; 

        while (choice < 1 || choice > 5) {

            cout << "I don't think that's valid?" << endl;
            cout << "Enter your choice (1, 2, 3, 4, 5): ";
            cin >> choice; 

        }

        if (choice != 5) {

            switch(choice) {
                case 1: {
                    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num = num1 + num2;

                    cout << "What is " << num1 << " + " << num2 << " ?" << endl
                        << "Key in your answer here." << endl;

                    cin >> answer;

                    if ( num == answer) {
                    cout << "Congratulations!" << endl;        
                    }
                    
                    else {
                    cout << "The answer is " << num << endl;
                    }
                    break;
                }
                case 2: {
                    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num = num1 - num2;

                    cout << "What is " << num1 << " - " << num2 << " ?" << endl
                        << "Key in your answer here." << endl;

                    cin >> answer;

                    if ( num == answer) {
                    cout << "Congratulations!" << endl;        
                    }
                    
                    else {
                    cout << "The answer is " << num << endl;
                    }
                    break;
                }
                case 3: {
                    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num = num1 * num2;

                    cout << "What is " << num1 << " * " << num2 << " ?" << endl
                        << "Key in your answer here." << endl;

                    cin >> answer;

                    if ( num == answer) {
                    cout << "Congratulations!" << endl;        
                    }
                    
                    else {
                    cout << "The answer is " << num << endl;
                    }
                    break;
                }
                case 4: {
                    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                    num = num1 / num2;

                    cout << "What is " << num1 << " ÷ " << num2 << " ?" << endl
                        << "Key in your answer here." << endl;

                    cin >> answer;

                    if ( num == answer) {
                    cout << "Congratulations!" << endl;        
                    }
                    
                    else {
                    cout << "The answer is " << num << endl;
                    }
                    break;
                }
            }
        }
    } while (choice != 5);
    cout << "Quit w.";

    return 0;
}