// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = LLONG_MIN;
    for (ll x = a; x <= b; ++x) {
        for (ll y = c; y <= d; ++y) {
            ans = max(ans, x - y);
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
    return 0;
}