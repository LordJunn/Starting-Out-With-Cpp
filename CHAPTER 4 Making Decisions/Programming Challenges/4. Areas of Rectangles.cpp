/* The area of a rectangle is the rectangle’s length times its width. Write a program that
asks for the length and width of two rectangles. The program should tell the user which
rectangle has the greater area, or if the areas are the same. */

#include <iostream>
using namespace std;

int main() {

    int len1, len2, wid1, wid2, area1, area2;

    cout << "Enter the length of rectangle 1:" << endl;
    cin >> len1;
    cout << "Enter the width of rectangle 1:" << endl;
    cin >> wid1; 

    area1 = len1 * wid1;   

    cout << "Enter the length of rectangle 2:" << endl;
    cin >> len2;
    cout << "Enter the width of rectangle 2:" << endl;
    cin >> wid2; 

    area2 = len2 * wid2;       

    if (area1 == area2) {
        cout << "Their areas are the same!" << endl;
    }
    else if (area1 > area2) {
        cout << "The first rectangle is bigger than the second rectangle." << endl;    
        cout << "The second rectangle is smaller than the first rectangle." << endl;                      
    }
    else {
        cout << "The second rectangle is bigger than the first rectangle." << endl;   
        cout << "The first rectangle is smaller than the second rectangle." << endl;      
    }

    return 0;
}