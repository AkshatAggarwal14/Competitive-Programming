#include <bits/stdc++.h>
using namespace std;

/*
here 0 means dont own stock
best([1, 2, 3, .. N], 0) -> 1. if you dont own stock at ith day -> either buy/dont buy
                            2. if you own a stock -> either sell/dont sell
when buying i: pay prices[i] + fee
when sell: get prices[i]

dp[i][0] = max profit made from day i to day n, given currently not holding stock, !own
dp[i][1] = max profit made from day i to day n, given currently holding a stock
ans: dp[0][0]

? when now owning either i dont want, or i buy
dp[i][!own] = max{dp[i + 1][!own], -(prices[i] + fee) + dp[i + 1][own]} {just bough stock}
dp[i][own] = max{prices[i] + dp[i + 1][!own], dp[i + 1][own]} {get profit prices[i] or skip}
*/
class Solution {
   public:
    Solution() {
        cin.tie(nullptr)->sync_with_stdio(false);
    }
    int maxProfit(vector<int>& P, int fee) {
        int n = int(size(P));
        vector<vector<int>> dp(n + 1, vector<int>(2));
        // dp[i][0] = max profit from day [i..n-1] without stock
        // dp[i][1] = max profit from day [i..n-1] with stock
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] - (P[i] + fee));
            dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + P[i]);
        }
        return dp[0][0];
    }
};