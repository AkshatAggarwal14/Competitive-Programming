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
    ll n;
    /*
    https://codeforces.com/contest/884/problem/C
        1. pi = j and only one, so one one relation ship
        2. We just have to connect two different loops and make it into larger one
        3. Loop:
            1 -> 2, 2-> 3, 3-> 1 (Here we can have 12,23,31,13,32,21,11,22,33) -> n^2, where n is size of a loop
        4. to maximise we need (a+b)^2 - a^2 - b^2 = 2*a*b <- product to be maximum <- basically 2 with maximum size of loops
    */
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
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}