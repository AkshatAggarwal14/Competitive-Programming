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
    // 2    ,7     ,15
    // 3 - 1, 7 - 2, 18 - 3 (from figure)
    // 1 * 3 - 1, 3 * 3 - 2, 6 * 3 - 3
    // 1 * 3 - 1, (1 + 2) * 3 - 2, (1 + 2 + 3) * 3 - 3,..
    ll n;
    cin >> n;
    ll ans = 0;
    while (n >= 2) {  // as 2 is minimum needed for constructing
        ll last = find_last_true(0LL, ll(1e9), [&](ll m) { return ((m * (m + 1)) / 2) * 3 - m <= n; });
        last = ((last * (last + 1)) / 2) * 3 - last;  // size of largest <= n
        n -= last, ans++;
    }
    cout << ans << '\n';
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