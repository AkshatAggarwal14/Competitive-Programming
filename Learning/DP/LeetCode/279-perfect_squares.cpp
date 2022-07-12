#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        vector<int> coins;
        for (int i = 1; i * i <= n; ++i) coins.push_back(i * i);
        int m = int(coins.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, n));  // filled with n as n 1's
        // unbound knapsack type thingy, with size of knapsack = n
        // dp[i][j] = min coins needed to make sum j using prefix from [0..i] coins
        // (c1 c2.. cm, n) ->   1. (c1 c2.. cm-1, n)
        //                      2. (c1 c2.. cm, n - cm)
        // O(n*sqrt(n)) time and space
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
        return dp[m][n];
    }
};

const int INF = 1e9;

class Solution2 {
   public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        // dp[i] = minimum numbers required to make i
        // O(n*sqrt(n)) time and O(n) space
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};