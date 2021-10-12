#include <bits/stdc++.h>

#include <Akshat.hpp>
using namespace std;
bool wordPattern(string pattern, string s) {
    map<char, string> mep;
    vector<string> vv;
    stringstream ss(s);
    string temp;
    while (ss >> temp) vv.emplace_back(temp);
    if (int(vv.size()) != int(pattern.size())) return false;
    int n = vv.size();
    for (int i = 0; i < n; i++) {
        if (!mep.count(pattern[i])) {
            mep[pattern[i]] = vv[i];
        } else {
            if (mep[pattern[i]] != vv[i]) return false;
        }
    }
    set<string> st;
    for (auto [x, y] : mep) st.insert(y);
    set<char> st2;
    for (auto c : pattern) st2.insert(c);
    if ((int)st.size() != (int)st2.size()) return false;
    return true;
}

int main() {
    string pattern;
    cin >> pattern;
    string s;
    cin.ignore();
    getline(cin, s);
    cout << wordPattern(pattern, s);
    return 0;
}