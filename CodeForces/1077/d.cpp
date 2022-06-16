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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (ll &x : a) cin >> x, ++cnt[x];
    // exaclty k elements, we can cut x times, x is the needed number of occurences
    ll max_cut = find_last_true(1LL, n, [&](ll X) -> bool {
        ll length = 0;
        for (auto &[x, y] : cnt) length += y / X;
        return length >= k;
    });
    vector<ll> res;
    for (auto &[x, y] : cnt) {
        if (sz(res) == k) break;
        ll times = y / max_cut;
        while (times--) {
            if (sz(res) == k) break;
            res.push_back(x);
        }
    }
    for (ll &x : res) cout << x << ' ';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}