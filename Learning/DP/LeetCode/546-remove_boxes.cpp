#include <bits/stdc++.h>
using namespace std;

int dp[102][102][102];
class Solution {
   public:
    int removeBoxes(vector<int> arr) {
        int n = int(arr.size());
        vector<pair<int, int>> groups;
        int count = 0;
        int last = arr[0];
        for (const int &item : arr) {
            if (item == last) {
                count++;
            } else {
                if (count) groups.push_back({last, count});
                last = item, count = 1;
            }
        }
        if (count) groups.push_back({last, count});
        int m = int(size(groups));
        /*
        ? Since (a+b)^2 > a^2 + b^2, where a > 0, b > 0, so it's better to greedy to remove all contiguous boxes of the same color, instead of split them.

        ? Recurrences:
        ? dp[i][j][extra]: Best possible score for groups G[i, j] given G[i] has some extra digits combined to it i.e. extra
        dp[i][j][extra]:    1. cost(size(G_i) + extra) + dp[i + 1][j][0]
                            2. dp[i + 1][i + 1][0] + dp[i + 2][j][extra + G_i]     {collapse G2}
                            3. dp[i + 1][i + 2][0] + dp[i + 3][j][extra + G_i]     {collapse G2G3}
                            3. dp[i + 1][i + 3][0] + dp[i + 4][j][extra + G_i]     {collapse G2G3G4}
                                ...
        ! Dimensions: dp[m][m][n]
        */
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= m; ++j)
                for (int k = 0; k <= n; ++k) dp[i][j][k] = 0;

        for (int L = m - 1; L >= 0; --L) {
            for (int R = L; R < m; ++R) {
                for (int extra = n - groups[L].second; extra >= 0; --extra) {
                    int &ans = dp[L][R][extra];
                    ans = (groups[L].second + extra) * (groups[L].second + extra) + dp[L + 1][R][0];
                    for (int nxt = L + 1; nxt <= R; ++nxt) {
                        if (groups[nxt].first == groups[L].first) {
                            ans = max(ans, dp[L + 1][nxt - 1][0] +
                                               dp[nxt][R][extra + groups[L].second]);
                        }
                    }
                }
            }
        }
        return dp[0][m - 1][0];
    }
};