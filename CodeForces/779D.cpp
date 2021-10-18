// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

string s, t;
vector<ll> v;
bool good(ll x) {
    string temp = s;
    // checking for each x
    for (int i = 0; i < x; ++i) temp[v[i]] = '.';
    ll pos(0);
    for (ll i = 0; i < s.length(); ++i) {
        if (temp[i] == t[pos]) pos++;
    }
    if (pos == t.length()) return true;
    return false;
}

void Solution() {
    cin >> s >> t;
    ll n = s.length();
    v.resize(n);
    for (auto &x : v) cin >> x, x--;
    ll l = 0, r = n;
    while (r > l + 1) {
        ll m = (l + r) >> 1;
        if (good(m))
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
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