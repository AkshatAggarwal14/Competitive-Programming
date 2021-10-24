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
    ll n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    if (n1 > 0) {
        if (n1 % 2 == 0) cout << 0;
        fo(i, n2) cout << 1;
        fo(i, (n1 + 1) / 2) cout << 10;
        fo(i, n0) cout << 0;
    } else {
        // n1 = 0 means either one must be 0
        if (n0 == 0)
            fo(i, n2 + 1) cout << 1;
        else
            fo(i, n0 + 1) cout << 0;
    }
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