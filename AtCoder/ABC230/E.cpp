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

// https://math.stackexchange.com/questions/487401/sum-of-floor-of-harmonic-progression-sum-i-1n-lfloor-frac-ni-rfloor-2-sum
void Solution() {
    ll n;
    cin >> n;
    ll sum = 0, k = ll(sqrt(n));
    for (int i = 1; i <= k; i++) sum += n / i;
    sum *= 2;
    sum -= k * k;
    cout << sum << '\n';
}

template <bool b>
ll binsearch(ll l, ll r, const auto &pred) {
    --l, ++r;
    for (ll m; m = (l + r) / 2, r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}
// returns first i in [l, r], p(i) false, and if none found, returns r + 1
ll find_first_false(ll l, ll r, const auto &p) { return binsearch<false>(l, r, p); }
// returns last i in [l, r], p(i) true, and if none found, returns l - 1
ll find_last_true(ll l, ll r, const auto &p) { return binsearch<true>(l, r, p); }

// https://codeforces.com/contest/1263/problem/C
void BS() {
    // for n = 5, n/i -> 5 2 1 1 1
    // looks like finding first and last occurence and adding
    // Binary search
    ll n;
    cin >> n;
    vector<ll> valid;  // contains all possible n / i
    for (ll i = 1; i * i <= n; ++i) {
        valid.push_back(i);
        if (i != n / i) valid.push_back(n / i);  // all possible n / i
    }
    // sort(all(valid)); <- not needed
    ll ans = 0;
    for (ll &v : valid) {
        ll i1 = find_first_false(1LL, n, [&](ll m) { return n / m > v; });
        ll i2 = find_last_true(1LL, n, [&](ll m) { return n / m >= v; });
        ans += (i2 - i1 + 1) * v;
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
    // ll tc; cin >> tc; while (tc--)
    // Solution();
    BS();
    return 0;
}