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
    ll n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    // 16 Ways to color corners
    for (ll i = 0; i <= 15; ++i) {
        ll U = u, R = r, L = l, D = d;
        if (i & 1)  // 1st bit
            U--, L--;
        if (i & 2)  //2nd bit
            L--, D--;
        if (i & 4)  //3rd bit
            D--, R--;
        if (i & 8)  //4th bit
            R--, U--;
        dbg(U, R, L, D);
        if (min({U, R, L, D}) >= 0 && max({U, R, L, D}) <= n - 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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