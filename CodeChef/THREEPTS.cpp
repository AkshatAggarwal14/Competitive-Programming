#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
using str = string;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void Solution(ll i) {
    // cout << "Case #" << i << ": ";
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    //B between A and C
    if (xb < min(xa, xc) || xb > max(xa, xc) || yb < min(ya, yc) || yb > max(ya, yc)) return void(cout << "NO\n");
    if (xa == xb || ya == yb || xb == xc || yb == yc)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution(i);
    return 0;
}