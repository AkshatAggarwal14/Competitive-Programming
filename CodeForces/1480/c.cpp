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

ll query(ll x) {
    cout << "? " << x << endl;
    ll ans;
    cin >> ans;
    return ans;
}

void Solution() {
    ll n;
    cin >> n;
    cout << find_first_false(1LL, n, [&](ll m) {
        ll left = LLONG_MAX, right = LLONG_MAX;
        ll val = query(m);
        if (m != 1) left = query(m - 1);
        if (m != n) right = query(m + 1);
        if (val < left && val < right) {
            cout << "! " << m << '\n';
            exit(0);
        }
        return (val > right);
    });
}

// clang-format off
int main() {
    Solution();
    return 0;
}