// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll find_first_false(ll l, ll r, const auto& pred) {
    --l, ++r;
    for (ll m; m = l + (r - l) / 2, r > l + 1;) (pred(m) ? l : r) = m;
    return r;
}

void Solution() {
    ll k, x;
    cin >> k >> x;
    cout << find_first_false(0LL, 2 * k - 2, [&](ll depth) {
        ll cnt = (depth * (depth + 1)) / 2;
        if (depth > k) cnt = (k * (k + 1)) / 2 + (k * (depth - k) - (depth - k) * (depth - k + 1) / 2);
        return cnt < x;
    }) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc;
    cin >> tc;
    while (tc--)
        Solution();
    return 0;
}