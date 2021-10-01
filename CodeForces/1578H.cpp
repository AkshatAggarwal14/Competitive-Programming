#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
string s;
ll n;

ll calc(ll l = 0, ll r = n - 1) {
    ll ctr = 0;
    if (l >= r) return 0;
    for (ll i = l; i <= r; ++i) {
        if (s[i] == '(') ctr++;
        if (s[i] == ')') ctr--;
        if (ctr == 0) {
            if (i == r) {
                //If it reaches the end without ctr becoming 0 must be extra ()
                // order("("+T+")") = order(T)
                return calc(l + 1, r - 1);
            }
            if (s[i + 1] == '-') {
                // max(T1 + 1, T2)
                return max(calc(l, i) + 1, calc(i + 3, r));
            }
        }
    }
    return 0;  // will never reach this
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> s;
    n = s.length();
    cout << calc() << '\n';
    return 0;
}