#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (auto &row : grid) cin >> row;

    vector<vector<int>> dp(h, vector<int>(w, 0));
    // dp[i][j] = number of paths to reach (i, j) from (1, 1)
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                if (grid[i][j] != '#') {
                    dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[h - 1][w - 1] << '\n';

    return 0;
}
