// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

template <bool b>
auto binsearch(auto l, auto r, const auto& pred) {
    --l, ++r;
    for (decltype(l) m; m = midpoint(l, r), r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}

// returns first i in [l, r], p(i) false, and if none found, returns r + 1
auto find_first_false(auto l, auto r, const auto& p) {
    return binsearch<false>(l, r, p);
}

// returns last i in [l, r], p(i) true, and if none found, returns l - 1
auto find_last_true(auto l, auto r, const auto& p) {
    return binsearch<true>(l, r, p);
}

void Solution() {
    ll n, k;
    cin >> n >> k;
    // if v increases he can definitely write more than n lines.
    // find first false where v does not lead to < n lines
    cout << find_first_false(1LL, n * k, [&](ll v) -> bool {
        ll cnt = 0, den = 1;
        while (v / den) {
            cnt += (v / den);
            den *= k;
        }
        return (cnt < n);
    });
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