#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll N = 1001, K = 1001;
const ll MOD = 1e9 + 7;  // 998244353;

ll dp[N][K];

void test() {
    ll n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));

    for (ll ahead = 0; ahead <= n; ++ahead) dp[ahead][1] = 1;
    for (ll age = 0; age <= k; ++age) dp[0][age] = 1;
    // dp[ahead][age] = dp[n - ahead][age - 1] + dp[ahead - 1][age]
    for (ll age = 2; age <= k; ++age) {
        for (ll ahead = 1; ahead <= n; ++ahead) {
            dp[ahead][age] = (dp[n - ahead][age - 1] + dp[ahead - 1][age]) % MOD;
        }
    }

    cout << dp[n][k] << '\n';
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
