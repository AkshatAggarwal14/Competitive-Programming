#include <bits/stdc++.h>
using namespace std;

// O(sz * n * m) TC and SC
class Solution {
   public:
    int findMaxForm(vector<string> &arr, int m, int n) {
        int dp[m + 1][n + 1];
        // dp[i][j]: size of largest set with i zeroes and j ones
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = 0;
        for (auto &s : arr) {
            int c0 = count(s.begin(), s.end(), '0');
            int c1 = int(s.size()) - c0;
            for (int i = m; i >= c0; --i) {
                for (int j = n; j >= c1; --j) {
                    // overwrite values at end using previous values
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
            }
        }
        return dp[m][n];
    }
};

// O(sz * n * m) TC and O(m * n) SC
class Solution2 {
   public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        // dp[i][j][k]: size of largest subset using first i strings with j zeroes and k ones
        int sz = int(strs.size());
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= sz; ++i) {
            string &s = strs[i - 1];
            int ones = count(s.begin(), s.end(), '1'), zeroes = int(s.size()) - ones;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    int &ans = dp[i][j][k];
                    ans = dp[i - 1][j][k];
                    if (zeroes <= j && ones <= k) {
                        ans = max(ans, 1 + dp[i - 1][j - zeroes][k - ones]);
                    }
                }
            }
        }
        return dp[sz][m][n];
    }
};