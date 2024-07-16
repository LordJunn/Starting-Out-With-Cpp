/* The local Driver’s License Office has asked you to write a program that grades the writ-
ten portion of the driver’s license exam. The exam has 20 multiple choice questions.
Here are the correct answers:
1. A
2. D
3. B
4. B
5. C
6. B
7. A
8. B
9. C
10. D
11. A
12. C
13. D
14. B
15. D
16. C
17. C
18. A
19. D
20. B
Your program should store the correct answers shown above in an array. It should ask
the user to enter the student’s answers for each of the 20 questions, and the answers
should be stored in another array. After the student’s answers have been entered, the
program should display a message indicating whether the student passed or failed the
exam. (A student must correctly answer 15 of the 20 questions to pass the exam.) It
should then display the total number of correctly answered questions, the total number
of incorrectly answered questions, and a list showing the question numbers of the
incorrectly answered questions.
Input Validation: Only accept the letters A, B, C, or D as answers. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int MCQ = 20;
char correctAns[MCQ] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};

// ADBBCBABCDACDBDCCADB for troubleshooting purposes

char checker(char&); // wow back to single checker
void getAns(const int, char[]);
int checkAns(const int, char[], char[]);
void passFail(const int, int);
void showIncorrect(const int, char[], char[]);

char studentAns[MCQ];

int main() {

    int correct;

    getAns(MCQ, studentAns);
    correct = checkAns(MCQ, studentAns, correctAns);
    passFail(MCQ, correct);

    if (correct < MCQ) {
        showIncorrect(MCQ, studentAns, correctAns);
    }

    return 0;
}



char checker(char &x) {

    cin >> x;
    while ((x != 'A') && (x != 'B') && (x != 'C') && (x != 'D')) {
        cout << "This selection isn't valid. ";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getAns(const int a, char b[]) {

    for (int i = 0; i < a; i++) {

        cout << "What is the answer for question #" << (i + 1) << "? ";
        b[i] = checker(b[i]);
        cout << endl;

    }  

}

int checkAns(const int a, char b[], char c[]) {

    int w = 0;

    for (int i = 0; i < a; i++) {

        if(b[i] == c[i]) {
            w++;
        }

    }

    return w;

}

void passFail(const int a, int b) {

    if(b >= 15) {
        cout << "You passed!" << endl;
    }
    else {
        cout << "You failed!" << endl;
    }
    cout << "Total number of correctly answered questions: " << b << endl;
    cout << "Total number of incorrectly answered questions: " << (a - b) << endl;

}

void showIncorrect(const int a, char b[], char c[]) {

    cout << "The question numbers of the incorrectly answered questions are: ";

    for (int i = 0; i < a; i++) {

        if(b[i] != c[i]) {

            if(i == (a - 1)) {
                cout << (i + 1) << ". ";
            }
            else {
                cout << (i + 1) << ", ";
            }

        }

    }

}

