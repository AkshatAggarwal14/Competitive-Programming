// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll k;
ll time_taken(ll v) {
    ll cnt = 0, den = 1;
    while (v / den != 0) {
        cnt += (v / den);
        den = den * k;
    }
    return cnt;
}

void Solution() {
    ll n;
    cin >> n >> k;
    ll l = 1, r = 1e12;
    while (r >= l) {
        ll m = l + (r - l) / 2;
        if (time_taken(m) >= n)
            r = m - 1;
        else
            l = m + 1;
    }
    cout << r + 1 << '\n';
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