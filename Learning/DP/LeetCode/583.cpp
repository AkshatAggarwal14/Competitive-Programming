#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

class Solution {
   public:
    int minDistance(string a, string b) {
        // len(a) + len(b) - 2 * len(lcs(a, b))
        int n = int(a.size()), m = int(b.size());
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int, int)> lcs = [&](int i, int j) {
            if (i < 0 || j < 0) return 0;
            int &ans = dp[i][j];
            if (ans != -1) return ans;
            if (a[i] == b[j])
                ans = 1 + lcs(i - 1, j - 1);
            else
                ans = max(lcs(i - 1, j), lcs(i, j - 1));
            return ans;
        };
        return n + m - 2 * lcs(n - 1, m - 1);
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution s;
    return 0;
}
