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

void test() {
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    ll coins = INF;
    for (ll i = 0; i <= ll(1e8); ++i) {
        ll sumk = i * k;
        if (sumk > m) break;
        ll left = m - sumk;
        coins = min(coins, max(i - ak, 0LL) + max(left - a1, 0LL));
        // cout << "k: " << i << " 1: " << left << ' ';
        // cout << " more k: " << max(i - ak, 0LL) << " more 1: " << max(left - a1, 0LL) << '\n';
    }

    cout << coins << '\n';
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
