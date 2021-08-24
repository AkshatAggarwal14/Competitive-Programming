#include <iostream>
using namespace std;

int main() {
    int age;
    cin >> age;
    try {
        if (age > 18) {
            cout << "Access granted - you are old enough.";
        } else if (age == 18) {
            throw 606;
        } else {
            throw 505;
        }
    } catch (int myNum) {
        if (myNum == 505) {
            cout << "Access denied - You must be at least 18 years old.\n";
            cout << "Error number: " << myNum;
        } else if (myNum == 606) {
            cout << "One more year for Access.";
        }
    }
}