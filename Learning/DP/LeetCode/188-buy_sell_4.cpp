#include <bits/stdc++.h>
using namespace std;

int dp[1001][2][101];

class Solution {
   public:
    //? O(N * K)
    //? Also to make 1 transaction you need 2 days
    //? so maximum transactions that you can make are n/2
    int maxProfit(int k, vector<int>& P) {
        int n = int(size(P));
        /*
        if we need for atmost k transactions:
        - best([1,2,3..,N], 0, k) - max profit for days[1, N] without a stock and we can do atmost k transactions
        - as soon as we sell, one transaction is complete
        ? States
        dp[i][!own][j]: max profit from days[i..n] -> no stock and atmost j transactions
        dp[i][own][j]: max profit from days[i..n] -> own a stock and atmost j transactions
        Final ans: dp[1][0][k]
        ? Recurrences
        dp[i][!own][j] ->   1. Buy stock - (-P[i] + dp[i + 1][own][j])
                            2. Dont buy stock - (dp[i + 1][!own][j])
        dp[i][own][j] ->    1. Sell stock - (P[i] + dp[i + 1][!own][j - 1])
                            2. Dont sell stock - (dp[i + 1][own][j])
        ? As we need dp[i + 1] to get dp[i], so we go opposite in loop
        ? As we need dp[][][j - 1] to get dp[][][j] we need to go in increasing loop
         */
        // int k = 2;
        k = min(k, n / 2 + 1);
        memset(dp, 0, sizeof(dp));
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1)));
        for (int day = n - 1; day >= 0; --day) {
            for (int trans = 0; trans <= k; ++trans) {
                // own a stock
                // max(sell and dec trans, dont sell)
                // cant sell if out of transactions
                dp[day][1][trans] = max(((trans > 0) ? P[day] + dp[day + 1][0][trans - 1] : 0),
                                        dp[day + 1][1][trans]);

                // dont own a stock
                // max(buy, dont buy)
                dp[day][0][trans] = max(-P[day] + dp[day + 1][1][trans],
                                        dp[day + 1][0][trans]);
            }
        }
        return dp[0][0][k];
    }
};