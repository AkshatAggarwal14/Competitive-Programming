#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;

void test() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);  // unique coins?
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    // unbound coin change 1 knapsack
    // dp[i][j] = ways to create sum j using first i coins

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j];  // didnt pick coin
                if (coins[i - 1] <= j)
                    (dp[i][j] += dp[i][j - coins[i - 1]]) %= MOD;  // picked coin
            }
        }
    }

    cout << dp[n][sum] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}

/*
3 5
1 2 3

ways: 5
[2 3] [1 2 2] [1 1 3] [1 1 1 1 1] [1 1 1 2]
*/
