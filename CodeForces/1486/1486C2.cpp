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

ll query(ll l, ll r) {
    if (l >= r) return -1;  // never equal
    cout << "? " << l << ' ' << r << endl;
    ll res;
    cin >> res;
    return res;
}

// if position is same, then ans in this segment, else next segment.

void Solution() {
    ll n;
    cin >> n;
    ll smax = query(1, n), ans = -1;
    if (query(1, smax) != smax) {
        /*
                        idx: smax, smax+1, smax+2,.., ... n
                        val: smax, ... ,.. ,..max, ... ,...
            query(smax,idx): !=     !=   !=   [==] <- all equal after this
        */
        ans = find_first_false(smax, n, [&](ll m) { return (query(smax, m) != smax); });
    } else {
        /*
                        idx: 1, 2, 3, ..., ..., smax
                        val: ...,... max,..,...,..smax
            query(smax,idx): ==  ==  [==]   != <- .. all not equal after this
        */
        ans = find_last_true(1LL, smax, [&](ll m) { return (query(m, smax) == smax); });
    }
    cout << "! " << ans << endl;
}

// clang-format off
int main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}