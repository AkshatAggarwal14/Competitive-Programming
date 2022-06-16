#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll find_first_false(ll l, ll r, const auto &pred) {
    --l, ++r;
    for (ll m; m = (l + r) / 2, r > l + 1;) (pred(m) ? l : r) = m;
    return r;
}
// returns first i in [l, r], p(i) false, and if none found, returns r + 1
void Solution() {
    ll k, x;
    cin >> k >> x;
    // till k-1 as returns k if all true.
    // 1+2+...m
    ll mx = find_first_false(0LL, k - 1, [&](ll m) { return (m * (m + 1)) / 2 < x; });
    mx = min(mx, k);
    ll cnt = (mx * (mx + 1)) / 2;
    ll rem = x - cnt;
    if (rem <= 0) return void(cout << mx << '\n');  // done in up triangle
    // (k-1)+(k-2) + .. (k-m) = km - m(m+1)/2;
    ll mn = find_first_false(0LL, k - 2, [&](ll m) { return (k * m - (m * (m + 1)) / 2) < rem; });
    cout << mx + mn << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    ll tc;
    cin >> tc;
    while (tc--)
        Solution();
    return 0;
}