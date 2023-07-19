#ifdef LOCAL
#include "debug.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

const int MX = 1e9;

struct item {
    int weight;
    ll value;
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, W;
    cin >> n >> W;
    vector<item> items(n);
    for (auto &it : items) cin >> it.weight >> it.value;

    // dp[i][w] = max possible sum in knapsack considering first i items, with w capacity of knapsack
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // dont
            dp[i][w] = dp[i - 1][w];
            if (w >= items[i - 1].weight) {
                // take it
                dp[i][w] = max(dp[i][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            }
        }
    }
    cout << dp[n][W] << '\n';

    return 0;
}
