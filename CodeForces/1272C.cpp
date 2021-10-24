// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, k;
    char c;
    cin >> n >> k;
    string s, allowed(k, '.');
    cin >> s;
    for (ll i = 0; i < k; ++i) cin >> allowed[i];
    s.push_back('.');
    ll ctr = 0, ans = 0;
    for (char &c : s) {
        if (allowed.find(c) != string::npos)
            ctr++;
        else {
            ans += (ctr * (ctr + 1)) / 2;
            ctr = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}