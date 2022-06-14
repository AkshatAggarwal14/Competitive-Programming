#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

class Solution {
   public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        auto dfs = [&](const auto &self, int i, int j) {
            if (i == n) return 0;
            int &ans = dp[i][j];
            if (ans != -1) return ans;
            return ans = triangle[i][j] + min(self(self, i + 1, j), self(self, i + 1, j + 1));
        };
        return dfs(dfs, 0, 0);
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution s;
    return 0;
}
