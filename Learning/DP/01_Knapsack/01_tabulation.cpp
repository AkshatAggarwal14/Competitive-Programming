#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

void test() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i) cin >> wt[i];
    for (int i = 0; i < n; ++i) cin >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    // dp[i][j] = max value stored in knapsack of weight j with first i items

    // initialisation - base condition from recursive
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    for (int i = 0; i <= W; ++i) dp[0][i] = 0;

    // iterative calculation
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (wt[i - 1] <= j)  // wt[i th item] <= j, gives 2 choices
                dp[i][j] =
                    max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else  // cant include
                dp[i][j] = dp[i - 1][j];
        }
    }

    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (wt[i - 1] <= j) dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i][j]);
        }
    }
    */

    cout << dp[n][W] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}

/*
3 50
10 20 30
60 100 120

answer = 220
*/