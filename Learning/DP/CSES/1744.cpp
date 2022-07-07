#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    /*
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        auto dfs = [&](const auto &self, int h, int w) {
            if (h == w) return 0;  // if square no need to cut
            int &ans = dp[h][w];
            if (ans != -1) return ans;
            ans = INT_MAX;
            for (int i = 1; i <= w / 2; ++i) {
                int temp = 1 + self(self, h, i) + self(self, h, w - i);
                ans = min(ans, temp);
            }
            for (int i = 1; i <= h / 2; ++i) {
                int temp = 1 + self(self, i, w) + self(self, h - i, w);
                ans = min(ans, temp);
            }
            if (w <= a && h <= b) dp[w][h] = ans;
            return ans;
        };
        cout << dfs(dfs, a, b) << '\n';
    */

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    // dp[i][j] = minimum cuts on rectangle of length i and breadth j to make a square
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) continue;
            int &ans = dp[i][j];
            if (ans != 0) continue;
            ans = INT_MAX;
            // cutting along width, j remains same
            for (int k = 1; k <= i / 2; ++k)  // only need to iterate until half as symmetrical
                ans = min(ans, 1 + dp[i - k][j] + dp[k][j]);
            // cutting along height, i remains same
            for (int k = 1; k <= j / 2; ++k)
                ans = min(ans, 1 + dp[i][j - k] + dp[i][k]);
            if (i <= b && j <= a) dp[j][i] = ans;  //! dp[i][j] = dp[j][i]
        }
    }
    cout << dp[a][b] << '\n';
    return 0;
}
