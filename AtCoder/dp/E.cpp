#ifdef LOCAL
#include "debug.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const int MAX_VAL = 1e3;

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

    const int VAL_SUM = n * MAX_VAL;
    int ans = 0;

    // dp[i][v] = min possible weight of knapsack considering first i items, with atleast v value of knapsack
    vector<vector<ll>> dp(n + 1, vector<ll>(VAL_SUM + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int v = 0; v <= VAL_SUM; ++v) {
            dp[i][v] = dp[i - 1][v];
            if (v >= items[i - 1].value) {
                dp[i][v] = min(dp[i][v], dp[i - 1][v - items[i - 1].value] + items[i - 1].weight);
            }
            if (dp[i][v] <= W) {
                ans = max(ans, v);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
