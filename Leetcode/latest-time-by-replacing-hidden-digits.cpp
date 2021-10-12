#include <bits/stdc++.h>

#include <Akshat.hpp>
using namespace std;

string maximumTime(string time) {
    string s = time;
    if (s[0] == '?' && (s[1] < '4' || s[1] == '?'))
        s[0] = '2';
    else if (s[0] == '?')
        s[0] = '1';

    if (s[3] == '?') s[3] = '5';

    if (s[1] == '?' && s[0] == '2')
        s[1] = '3';
    else if (s[1] == '?' && s[0] == '1')
        s[1] = '9';
    if (s[1] == '?' && s[0] == '0') s[1] = '9';

    if (s[4] == '?') s[4] = '9';

    return s;
}

int main() {
    string s;
    cin >> s;
    cout << maximumTime(s);
    return 0;
}