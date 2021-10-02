// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    for (ll i = 0; i < n - 1; ++i) {
        if (s[i] != t[i]) {
            swap(s[i], s[i + 1]);
            break;
        }
    }
    if (s != t)
        cout << "No\n";
    else
        cout << "Yes\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}