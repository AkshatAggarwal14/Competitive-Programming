#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const int INF = 1e9;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);  // unique coins?
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    // dp[i][j] = min number of coins needed to make sum = j using first i coins.

    for (int i = 0; i <= sum; ++i) dp[0][i] = INF;
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;

    // need minimum number of coins
    // minimum after taking or not
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];
            // 1 + dp[i][j - coins[i - 1]] means coin is included
            // dp[i - 1][j] means coin was not included
            if (coins[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i][j]);
        }
    }
    cout << ((dp[n][sum] == INF) ? -1 : dp[n][sum]) << '\n';
    return 0;
}
