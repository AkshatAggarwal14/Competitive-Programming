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
    ll L = 0, R = m / k;

    // ternary search on number of ks needed
    auto can = [&](ll mid) {
        if (k * mid > m) return INF;
        ll l_i = m - k * mid;
        return max(l_i - a1, 0LL) + max(mid - ak, 0LL);
    };

    --L, ++R;

    while (R > L + 1) {
        ll M = (R + L) / 2;
        if (can(M) <= can(M + 1)) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << can(L + 1) << '\n';
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
