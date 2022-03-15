/*
    coins[]: 1 2 3
    sum    : 5
    ways   : [2 3] [1 2 2] [1 1 3] [1 1 1 1 1] [1 1 1 2] ...
    So to find total number of ways to make given sum, with coins

    For every coin, we have a choice to include or not include and IF we include, we can include multiple - unbounded

    W -> sum
    coins[] -> wt[]
    kinda like count subset sums
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

void test() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);  // unique coins?
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    // dp[i][j] = ways to create sum j using first i elements.
    for (int i = 0, cnt = 0; i <= n; ++i) {
        if (i > 0 && coins[i - 1] == 0) ++cnt;
        dp[i][0] = (1LL << cnt);
    }
    for (int i = 1; i <= sum; ++i) dp[0][i] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (coins[i - 1] <= j)
                dp[i][j] += dp[i][j - coins[i - 1]];  // i elements again with one more coin of ith type
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
