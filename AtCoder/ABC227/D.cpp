#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

template <bool b>
ll binsearch(ll l, ll r, const auto& pred) {
    --l, ++r;
    for (ll m; m = (l + (r - l) / 2), r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}

void Solution() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    // T T T ... T F F F ...
    cout << binsearch<true>(1LL, (ll)1e18 / k, [&](ll projects) {  // 1e18/k
        ll total = 0;
        // min(employee in a dept, projects)
        for (ll& x : a) total += min(projects, x);
        return total >= k * projects;
    }) << '\n';
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