#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto& container) -> ll { return container.size(); };

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
    ll s, b;
    cin >> s >> b;
    vector<ll> a(s);
    for (ll& x : a) cin >> x;
    vector<pair<ll, ll>> bases(b);
    for (auto& [x, y] : bases) cin >> x >> y;
    ranges::sort(bases);
    for (ll i = 1; i < b; ++i) bases[i].second += bases[i - 1].second;
    dbg(bases);
    for (ll i = 0; i < s; ++i) {
        ll idx = find_last_true(0LL, b - 1, [&](ll m) {
            return (bases[m].first <= a[i]);
        });
        if (idx == -1)
            cout << 0;
        else
            cout << bases[idx].second;
        cout << ' ';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}