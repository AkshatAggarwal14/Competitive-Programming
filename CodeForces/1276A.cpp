#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

void Solution() {
    string s;
    cin >> s;
    ll n = sz(s);
    vector<ll> pos;
    for (ll i = 0; i < n; ++i) {
        if (i + 4 <= n - 1 && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e') {
            pos.push_back(i + 3);
            i += 4;
        } else if (i + 2 <= n - 1 && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
            pos.push_back(i + 2);
            i += 2;
        } else if (i + 2 <= n - 1 && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
            pos.push_back(i + 2);
            i += 2;
        }
    }
    cout << sz(pos) << '\n';
    for (auto x : pos) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}