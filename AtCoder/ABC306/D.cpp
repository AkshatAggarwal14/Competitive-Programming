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
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));

    // dp[index][lastEaten] = max value after eating [index, n] with given lastEaten value
    dp[n][0] = dp[n][1] = 0;
    for (ll i = n - 1; i >= 0; --i) {
        dp[i][0] = dp[i + 1][0];
        dp[i][1] = dp[i + 1][1];

        dp[i][0] = max(dp[i][0], dp[i + 1][x[i]] + y[i]);
        dp[i][1] = max(dp[i][1], (x[i] == 1) ? 0LL : dp[i + 1][x[i]] + y[i]);
    }
    cout << max(dp[0][0], dp[0][1]) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
