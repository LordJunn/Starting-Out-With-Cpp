/* One of your professors has asked you to write a program to grade her final exams,
which consist of only 20 multiple-choice questions. Each question has one of four pos-
sible answers: A, B, C, or D. The file CorrectAnswers.txt contains the correct answers
for all of the questions, with each answer written on a separate line. The first line
contains the answer to the first question, the second line contains the answer to the
second question, and so forth. (Download the book’s source code from the companion
Web site at www.pearsonhighered.com/gaddis. You will find the file in the Chapter 07
folder.)
Write a program that reads the contents of the CorrectAnswers.txt file into a char
array, and then reads the contents of another file, containing a student’s answers, into a
second char array. (You can use the file StudentAnswers.txt for testing purposes. This
file is also in the Chapter 07 source code folder, available on the book’s companion
Web site.) The program should determine the number of questions that the student
missed and then display the following:
• A list of the questions missed by the student, showing the correct answer and the
incorrect answer provided by the student for each missed question
• The total number of questions missed
• The percentage of questions answered correctly. This can be calculated as
Correctly Answered Questions ÷ Total Number of Questions
• If the percentage of correctly answered questions is 70% or greater, the program
should indicate that the student passed the exam. Otherwise, it should indicate that
the student failed the exam. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int MCQ = 20,
          pass = 70;

void getInfoFromFile(char[], string);
int checkAns(const int, char[], char[]);
void passFail(const int, int);
void showIncorrect(const int, char[], char[]);
void showCorrect(const int, char[], char[]);

char correctAns[MCQ];
char studentAns[MCQ];

int main() {

    string correctA, studentA;
    int correct;

    cout << "File name to open to import correct answers from? ";
    cin >> correctA;
    getInfoFromFile(correctAns, correctA);
    cout << endl;

    cout << "File name to open to import student answers from? ";
    cin >> studentA;
    getInfoFromFile(studentAns, studentA);
    cout << endl;

    correct = checkAns(MCQ, correctAns, studentAns);
    passFail(MCQ, correct);
    cout << endl;

    if (correct > 0) {
        showCorrect(MCQ, correctAns, studentAns);
        cout << endl;
    }

    if (correct < MCQ) {
        showIncorrect(MCQ, correctAns, studentAns);
        cout << endl;
    }

    return 0;
}


void getInfoFromFile(char array[], string fileName) {

    ifstream inputFile;
    inputFile.open(fileName);

    int i = 0;

    if(inputFile) {
        cout << "File opened successfully." << endl;
        for(i = 0; i < MCQ; i++) {
            inputFile >> array[i];
        }
            inputFile.close();
    }
    else {
        cout << "Nope, can't find or open that file." << endl;
        cout << "The program will now kill itself.";
        exit(0);
    }
    i = 0;
    inputFile.close();
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

    double c = (b*100)/a;

    cout << "You've scored " << c << "% on your test!" << endl;

    if(c >= pass) {
        cout << "You passed!" << endl;
    }
    else {
        cout << "You failed!" << endl;
        cout << "You need at least " << (pass - c) << " more marks to pass." << endl;
    }
    cout << "Total number of correctly answered questions: " << b << endl;
    cout << "Total number of incorrectly answered questions: " << (a - b) << endl;

}

void showCorrect(const int a, char b[], char c[]) {

    cout << "The question numbers of the correctly answered questions are:" << endl;

    for (int i = 0; i < a; i++) {

        if(b[i] == c[i]) {

            cout << (i + 1) << ". " << c[i] << endl;

        }

    }

}

void showIncorrect(const int a, char b[], char c[]) {

    cout << "The question numbers of the incorrectly answered questions (and the correct answers) are:" << endl;

    for (int i = 0; i < a; i++) {

        if(b[i] != c[i]) {

            cout << (i + 1) << ". " << c[i] << " (" << b[i]  << ")" << endl;

        }

    }

}

