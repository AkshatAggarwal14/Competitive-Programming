#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;
/*
    the first cutter will take orders for toys with patterns from 1 to x1+x2 / 2
    the second - for toys with patterns from x1+x2 / 2 to x2+x3 / 2
    the third - for toys with patterns from x2+x3 / 2 to 10^9
.
*/
void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    // binary search on max difference which covers the array in <= 3 parts
    ll L = -1, R = a[n - 1] - a[0] + 1;

    auto can = [&](ll mid) {
        // if we have delta = x, we can go from a[i] to a value a[i] + 2 * x
        ll pos = 0;
        for (int i = 0; i < 3; ++i) {
            auto nxt = upper_bound(a.begin(), a.end(), a[pos] + 2 * mid) - a.begin();
            pos = nxt;
            if (pos == n) break;
        }
        return pos == n;
    };

    while (R > L + 1) {
        ll M = (L + R) / 2;
        if (can(M)) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << R << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
