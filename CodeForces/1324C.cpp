// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    // Ignore 'L's just use 'R's
    string s;
    cin >> s;
    s = "R" + s + "R";
    ll n = s.length();
    vector<ll> pos;
    for (ll i = 0; i < n; ++i)
        if (s[i] == 'R') pos.push_back(i);
    ll ans = 0;
    for (ll i = 1; i < (ll)pos.size(); ++i) {
        ans = max(ans, pos[i] - pos[i - 1]);
    }
    cout << ans << '\n';
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
    return 0;
}