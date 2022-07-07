#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int A = s1.size(), B = s2.size(), C = s3.size();
        if (A + B != C) return false;
        vector<vector<bool>> dp(A + 1, vector<bool>(B + 1));
        // dp[i][j] = whether s3[0..(i + j - 1)] is the interleaving of s1[0..(i - 1)] and s2[0..(j - 1)]
        for (int i = 0; i <= A; i++)
            for (int j = 0; j <= B; j++) {
                if (i == 0 && j == 0)  // both empty
                    dp[i][j] = true;
                else if (i == 0)  // one is empty
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[j - 1]);
                else if (j == 0)
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1]);
                else
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                               (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        return dp[A][B];
    }
};