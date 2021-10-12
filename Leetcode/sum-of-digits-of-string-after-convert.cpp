#include <bits/stdc++.h>

#include <Akshat.hpp>
using namespace std;

string transform(string s) {
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        res += (s[i] - '0');
    }
    return to_string(res);
}

int getLucky(string s, int k) {
    string res = "";
    for (int i = 0; i < (int)s.size(); ++i) {
        int temp = (s[i] - 'a' + 1);
        if (s[i] < 'j') {
            res += (temp + '0');
        } else {
            res += (temp / 10 + '0');
            res += (temp % 10 + '0');
        }
    }
    // dbg(res);
    while (k--) res = transform(res);
    return stoi(res);
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << getLucky(s, k);
    return 0;
}