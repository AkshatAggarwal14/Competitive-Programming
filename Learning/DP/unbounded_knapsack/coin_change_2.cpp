/*
    coins[]: 1 2 3
    sum    : 5
    ways   : [2 3] [1 2 2] [1 1 3] [1 1 1 1 1] [1 1 1 2] ...
    minimum coins: [2 3] -> 2
    How many minimum number of coins needed to make given sum?

    For every coin, we have a choice to include or not include and IF we include, we can include multiple - unbounded

    W -> sum
    coins[] -> wt[]
*/

#ifdef LOCAL
#include "debug.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const int INF = 1e9;

void test() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);  // unique coins?
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
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
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}

/*
3 5
1 2 3

ans : 2
ways: 5
[2 3] [1 2 2] [1 1 3] [1 1 1 1 1] [1 1 1 2]
*/
