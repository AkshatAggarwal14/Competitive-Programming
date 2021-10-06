// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll stoi64(string s) {
    ll res = 0;
    for (char &c : s) res = res * 10 + (c - '0');
    return res;
}

void Solution() {
    string s;
    char c;
    cin >> s >> c;
    ll n1 = stoi64(s);
    if (c == '0') {
        for (ll i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                s[i]++;
                for (ll j = i + 1; j < s.length(); ++j) s[j] = '1';
                break;
            }
        }
        cout << stoi64(s) - n1 << '\n';
        return;
    } else if (c < '9') {
        for (ll i = 0; i < s.length(); ++i) {
            if (s[i] == c) {
                s[i]++;
                for (ll j = i + 1; j < s.length(); ++j) s[j] = '0';
                break;
            }
        }
        cout << stoi64(s) - n1 << '\n';
        return;
    } else {
        // if c == '9'
        if (s[0] == '9') {
            cout << static_cast<ll>(pow(10, s.length())) - n1 << '\n';
            return;
        }
        for (ll i = 0; i < s.length(); ++i) {
            if (s[i] == '9') {
                s[i] = '0';
                for (ll j = i + 1; j < s.length(); ++j) s[j] = '0';
                if (s[i - 1] != '8') {
                    s[i - 1]++;
                    break;
                }
                ll I = i;
                while (I >= 1 && s[I - 1] == '8') {
                    s[I - 1] = '0';
                    I--;
                }
                if (I)
                    s[I - 1]++;
                else {
                    cout << static_cast<ll>(pow(10, s.length())) - n1 << '\n';
                    return;
                }
                break;
            }
        }
        // cerr << s << '\n';
        cout << stoi64(s) - n1 << '\n';
        return;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc;
    cin >> tc;
    while (tc--)
        Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}