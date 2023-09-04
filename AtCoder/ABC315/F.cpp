#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
using ld = long double;

const ll INF = 1e18;
const ll N = 1e4 + 5;
const ll MX = 40;
ld dp[N][MX];

void test() {
    ll n;
    cin >> n;
    vector<array<ll, 2>> a(n);
    for (auto &x : a) cin >> x[0] >> x[1];

    auto dist = [&](ll i, ll j) -> ld {
        return sqrtl(ld(
            (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) +
            (a[i][1] - a[j][1]) * (a[i][1] - a[j][1])));
    };

    auto cost = [&](ll skips) {
        if (skips == 0) return ld(0);
        return ld(1LL << (skips - 1));
    };

    // dp[i][s] = minimum sum for [1..i] with s skips yet
    for (ll i = 1; i < n; ++i) {
        for (ll skips = 0; skips < MX; ++skips) {
            dp[i][skips] = INF;
        }
    }

    for (ll skips = 0; skips < MX; ++skips) {
        dp[0][skips] = 0;
    }

    for (ll i = 1; i < n; ++i) {
        for (ll skips = 0; skips < MX; ++skips) {
            for (ll jumps = 0; jumps <= skips; ++jumps) {
                ll prevId = i - jumps - 1;
                if (prevId >= 0) {
                    dp[i][skips] = min(dp[i][skips], dp[prevId][skips - jumps] + dist(prevId, i));
                }
            }
        }
    }

    ld res = INF;

    for (ll skips = 0; skips < MX; ++skips) {
        res = min(res, dp[n - 1][skips] + cost(skips));
    }

    cout << res << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(10);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
