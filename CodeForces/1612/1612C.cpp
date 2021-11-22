#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

template <bool b>
auto binsearch(auto l, auto r, const auto &pred) {
    --l, ++r;
    for (decltype(l) m; m = midpoint(l, r), r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}

// returns first i in [l, r], p(i) false, and if none found, returns r + 1
auto find_first_false(auto l, auto r, const auto &p) {
    return binsearch<false>(l, r, p);
}

// returns last i in [l, r], p(i) true, and if none found, returns l - 1
auto find_last_true(auto l, auto r, const auto &p) {
    return binsearch<true>(l, r, p);
}

void Solution() {
    ll k, x;
    cin >> k >> x;
    // ll total = k * k;
    if (x >= k * k) return void(cout << 2 * k - 1 << '\n');
    ll mx = find_first_false(0LL, k, [&](ll m) {
        return (m * (m + 1)) / 2 < x;
    });
    mx = min(mx, k);
    ll cnt = (mx * (mx + 1)) / 2;
    ll rem = x - cnt;
    dbg(mx, rem);
    if (rem <= 0) return void(cout << mx << '\n');
    ll mn = find_first_false(0LL, k - 1, [&](ll m) {
        return (k * m - (m * (m + 1)) / 2) < rem;
    });
    cout << mx + mn << '\n';
    dbg(mn);
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}