#include <bits/stdc++.h>
using namespace std;

int dp[102][102][102];
class Solution {
   public:
    int solve(int i, int j, int k, vector<int>& boxes) {
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        if (i == j)
            return (k + 1) * (k + 1);
        dp[i][j][k] = solve(i + 1, j, 0, boxes) + (k + 1) * (k + 1);
        if (k < boxes.size()) {
            for (int l = i + 1; l <= j; l++) {
                if (boxes[l] == boxes[i])
                    dp[i][j][k] = max(dp[i][j][k], ((l - 1 == i) ? 0 : solve(i + 1, l - 1, 0, boxes)) + solve(l, j, k + 1, boxes));
            }
        }
        return dp[i][j][k];
    }

    int removeBoxes(vector<int>& boxes) {
        int n = int(boxes.size());
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, 0, boxes);
    }
};