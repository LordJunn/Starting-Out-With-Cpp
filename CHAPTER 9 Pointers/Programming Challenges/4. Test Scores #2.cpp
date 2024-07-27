/* Modify the program of Programming Challenge 2 to allow the user to enter name-score
pairs. For each student taking a test, the user types the student’s name followed by the
student’s integer test score. Modify the sorting function so it takes an array holding
the student names and an array holding the student test scores. When the sorted list
of scores is displayed, each student’s name should be displayed along with his or her
score. In stepping through the arrays, use pointers rather than array subscripts. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(double&, int, int);
void getArrayInfo(double*, string*, int);
void selectionSort(double*, string*, int);
double average(double, int);

int main() {

    double *scoresArray = nullptr,
            scores,
            avg;

    string *namesArray = nullptr;

    int amount, 
        count, 
        total = 0;

    cout << "How many test scores do you wish to put into the array? ";
    cin >> amount;

    scoresArray = new double[amount];
    namesArray = new string[amount];

    cout << "Enter the students name and their respective test scores below:" << endl;
    getArrayInfo(scoresArray, namesArray, amount);

    selectionSort(scoresArray, namesArray, amount);
    cout << "Displaying the contents of the sorted test scores with their names:" << endl;
    for (int i = 0; i < amount; i++) {
        cout << "Student #" << (i + 1) << " name: " << *(namesArray + i) << endl;
        cout << *(namesArray + i) << "'s test score: " << *(scoresArray + i) << endl;
        total += *(scoresArray + i);
    }
    cout << endl;

    avg = average(total, amount);
    cout << "Average of the test scores: " << avg;

    delete[] scoresArray;
    scoresArray = nullptr;

    return 0;
}

int checker(double &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getArrayInfo(double *array, string *brray, int amount) {

    for (int i = 0; i < amount; i++) {

        cout << "Name of student #" << (i + 1) << "? ";
        cin >> *(brray + i);
        cout << "Test score for " << (*(brray + i)) << "? ";
        *(array + i) = checker(*(array + i), 0, 100);
    }    
}

void selectionSort(double *array, string *brray, int size) {
    int startScan, minIndex;
    int minValue;
    string minName;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = *(array + startScan);
        minName = *(brray + startScan);
        for (int index = startScan + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = *(array + index);
                minName = *(brray + index);
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

double average(double total, int amount) {

    double avg = total/amount;
    return avg;

}

