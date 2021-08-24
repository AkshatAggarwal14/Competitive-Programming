// https :  //www.geeksforgeeks.org/exception-handling-c/
// quiz has nice questions too
#include <iostream>
using namespace std;

int main() {
    int age;
    try {
        cin >> age;
        if (age >= 18)
            cout << "Access granted - you are old enough.";
        else if (age < 18)
            throw 505;
        else
            throw "Wrong input";
    } catch (int Num) {
        cout << "Access denied - You must be at least 18 years old.\n";
    } catch (...) {
        cout << "Wrong input, Default exception";
    }
}
// throw can also be resued inside a catch to rethrow caught exception