#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
#define int long long

void test() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i) cin >> wt[i] >> val[i];

    // in one iteration we just use, current and previous row, thus DP can be space optimised to O(2*W) instead of O(n*W)
    vector<vector<int>> dp(2, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0)
                dp[i % 2][w] = 0;
            else {
                dp[i % 2][w] = dp[(i - 1) % 2][w];
                if (wt[i - 1] <= w)
                    dp[i % 2][w] = max(val[i - 1] + dp[(i - 1) % 2][w - wt[i - 1]], dp[i % 2][w]);
            }
        }
    }

    cout << dp[n % 2][W] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
