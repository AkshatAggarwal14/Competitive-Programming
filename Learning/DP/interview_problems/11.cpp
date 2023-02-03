// https://leetcode.com/problems/domino-and-tromino-tiling/description/
#include <bits/stdc++.h>
using namespace std;

long long dp[1001][2];
const int MOD = 1e9 + 7;

class Solution {
   public:
    int numTilings(int n) {
        // dp[i][1]: perfect rectangle of i length
        // dp[i][2]: L with 1 row filled and i length
        // dp[i][1]: dp[i - 1][1] + dp[i - 2][1] + 2 * dp[i - 1][2]
        // dp[i][2]: dp[i - 2][1] + dp[i - 1][2]
        // https://leetcode.com/problems/domino-and-tromino-tiling/solutions/116506/python-recursive-dp-solution-with-cache-w-explanation/comments/116938
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[1][0] = dp[2][1] = 1, dp[2][0] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = ((dp[i - 1][0] + dp[i - 2][0]) % MOD +
                        (2 * 1LL * dp[i - 1][1]) % MOD) %
                       MOD;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % MOD;
        }
        return dp[n][0];
    }
};