#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;

// If you can do same task for 'K' consecutive days

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, K;
    cin >> n >> K;
    vector<array<ll, 3>> a(n), dp(n);
    for (auto &[A, B, C] : a) cin >> A >> B >> C;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
        ll sum = a[i][0];
        dp[i][0] = -INF;
        for (int k = 1; k <= K && i - k >= 0; ++k) {
            // consider doing other activities before and doing this one for past k - 1 days and today.
            dp[i][0] = max(dp[i][0], max(dp[i - k][1], dp[i - k][2]) + sum);
            sum += a[i - k][0];
        }

        sum = a[i][1];
        dp[i][1] = -INF;
        for (int k = 1; k <= K && i - k >= 0; ++k) {
            dp[i][1] = max(dp[i][1], max(dp[i - k][0], dp[i - k][2]) + sum);
            sum += a[i - k][1];
        }

        sum = a[i][2];
        dp[i][2] = -INF;
        for (int k = 1; k <= K && i - k >= 0; ++k) {
            dp[i][2] = max(dp[i][2], max(dp[i - k][0], dp[i - k][1]) + sum);
            sum += a[i - k][2];
        }
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return 0;
}
