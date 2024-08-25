/* In this programming challenge you will create a simple trivia game for two players. The
program will work like this:
• Starting with player 1, each player gets a turn at answering five trivia questions.
(There are a total of 10 questions.) When a question is displayed, four possible
answers are also displayed. Only one of the answers is correct, and if the player
selects the correct answer he or she earns a point.
• After answers have been selected for all of the questions, the program displays the
number of points earned by each player and declares the player with the highest
number of points the winner.
In this program you will design a Question class to hold the data for a trivia question.
The Question class should have member variables for the following data:
• A trivia question
• Possible answer #1
• Possible answer #2
• Possible answer #3
• Possible answer #4
• The number of the correct answer (1, 2, 3, or 4)
The Question class should have appropriate constructor(s), accessor, and mutator
functions.
The program should create an array of 10 Question objects, one for each trivia ques-
tion. Make up your own trivia questions on the subject or subjects of your choice for
the objects. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Trivia {
   private:
    int score1 = 0;
    int score2 = 0;

   public:
    void p1C() {
        score1++;
    }
    void p2C() {
        score2++;
    }
    int getP1() {
        return score1;
    }
    int getP2() {
        return score2;
    }

};

void askQuestion(int, Trivia&);

int main() {
    Trivia gamer;
    const int max = 10;

    int p1 = 0, 
        p2 = 0;

    for(int i = 0; i < max; i++) {
        askQuestion(i, gamer);
    }

    p1 = gamer.getP1();
    p2 = gamer.getP2();

    if(p1 > p2) {
        cout << "Player 1 won!" << endl;
        cout << "They have a lead of " << p1 - p2 << " points compared to Player 2. " << endl;
    }
    else if (p2 > p1) {
        cout << "Player 2 won!" << endl;
        cout << "They have a lead of " << p2 - p1 << " points compared to Player 2. " << endl;
    }
    else {
        cout << "It's a tie as both players scored " << p1 << " points." << endl;
    }

    return 0;
}

void askQuestion(int qNum, Trivia& game) { // gpt as i lazy
    string questions[] = {
        "What is the capital of France?\n a) London\n b) Paris\n c) Berlin\n d) Rome\n",
        "Who painted the Mona Lisa?\n a) Leonardo da Vinci\n b) Vincent van Gogh\n c) Pablo Picasso\n d) Michelangelo\n",
        "What is the chemical symbol for water?\n a) Wo\n b) Wa\n c) H2O\n d) Wt\n",
        "Which planet is known as the Red Planet?\n a) Mars\n b) Jupiter\n c) Saturn\n d) Venus\n",
        "Who wrote \"Romeo and Juliet\"?\n a) William Shakespeare\n b) Charles Dickens\n c) Jane Austen\n d) Mark Twain\n",
        "What is the tallest mammal on Earth?\n a) Lion\n b) Elephant\n c) Giraffe\n d) Bear\n",
        "Which country is famous for its pyramids?\n a) China\n b) Brazil\n c) Egypt\n d) India\n",
        "What is the largest ocean on Earth?\n a) Atlantic Ocean\n b) Indian Ocean\n c) Arctic Ocean\n d) Pacific Ocean\n",
        "What is the currency of Japan?\n a) Yuan\n b) Euro\n c) Yen\n d) Dollar\n",
        "Who was the first person to step on the moon?\n a) Neil Armstrong\n b) Buzz Aldrin\n c) Yuri Gagarin\n d) John Glenn\n"
    };
    
    string answers[] = {"b", "a", "c", "a", "a", "c", "c", "d", "c", "a"};

    cout << "Question " << qNum + 1 << ":" << endl;
    cout << questions[qNum] << endl;

    string answer1, answer2;
    cout << "Player 1, enter your answer (a, b, c, or d): ";
    cin >> answer1;
    cout << "Player 2, enter your answer (a, b, c, or d): ";
    cin >> answer2;

    // Compare the answer with the correct answer
    if (answer1 == answers[qNum] && answer2 == answers[qNum]) {
        game.p1C();
        game.p2C();
    } 
    else if(answer1 == answers[qNum]) {
        game.p1C();
    }
    else if(answer2 == answers[qNum]) {
        game.p2C();
    }

}