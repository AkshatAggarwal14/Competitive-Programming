#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[102][102];

class Solution {
   public:
    int strangePrinter(string s) {
        int n = int(s.size());
        // {g1 g2 g3 .. gn} -> 1. we either paint in parts or we repaint small group
        memset(dp, 0, sizeof(dp));
        for (int L = n - 1; L >= 0; --L) {
            for (int R = L; R < n; ++R) {
                dp[L][R] = 1;
                if (L < R) dp[L][R] += dp[L + 1][R];  // bnreak here
                for (int k = L + 1; k <= R; ++k) {
                    if (s[k] == s[L]) {  // break when found same
                        dp[L][R] = min(dp[L][R], dp[L + 1][k - 1] + dp[k][R]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};