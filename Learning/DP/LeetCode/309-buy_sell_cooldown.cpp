#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    Solution() {
        cin.tie(nullptr)->sync_with_stdio(false);
    }
    int maxProfit(vector<int>& P) {
        int n = int(size(P));
        // dp[i][own][cooldown]: if under cooldown cant buy stock
        // dp[i]: maximum profit from day i to day n
        // dp[i][0][0]: max profit in days[i..n] such that no stock owned + no cooldown
        // dp[i][0][1]: max profit in days[i..n] such that no stock owned but under a cooldown <- cannot buy need stock
        // dp[i][1][*]
        // dp[i][0] - no stock + no cooldown, dp[i][1] - no stock + cooldown, dp[i][2] - have owned stock
        vector<vector<int>> dp(n + 1, vector<int>(3));
        // if own   -> sell         -> dp[i][2] = P[i] + dp[i + 1][1] {sell and then have cooldown}
        //          -> dont sell    ->  dp[i + 1][2]
        // if not own   -> if under cooldown        -> dp[i + 1][0] {as cooldown goes away}
        //              -> if not under cooldown    -> dp[i + 1][0], -P[i] + dp[i + 1][2] {just bought stock}
        for (int i = n - 1; i >= 0; --i) {
            dp[i][2] = max(dp[i + 1][2], P[i] + dp[i + 1][1]);
            dp[i][1] = dp[i + 1][0];
            dp[i][0] = max(dp[i + 1][0], -P[i] + dp[i + 1][2]);
        }
        return dp[0][0];
    }
};