#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

// basic knapsack
void test() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int &H : h) cin >> H;
    for (int &S : s) cin >> S;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (h[i - 1] <= j) dp[i][j] = max(dp[i][j], s[i - 1] + dp[i - 1][j - h[i - 1]]);
        }
    }
    cout << dp[n][x] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
