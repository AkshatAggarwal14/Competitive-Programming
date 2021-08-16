#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    /* example:
    if input is 
    2
    abc def
    ab cd

    it is acually
    2\n
    abc def\n
    ab cd\n

    Thus in loop t=2;
    s='\n'
    then next s='abc def\n'

    thus we use cin.ignore()
    */
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << s << '\n';
    }
}