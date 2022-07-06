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

void test() {
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (auto &x : grid)
        for (auto &y : x) cin >> y;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    // dp[i][j] = number of ways to move to (i, j) going only down or right
    for (ll i = 0; i < n && grid[i][0] == '.'; ++i) dp[i][0] = 1;
    for (ll i = 0; i < n && grid[0][i] == '.'; ++i) dp[0][i] = 1;
    for (ll i = 1; i < n; ++i) {
        for (ll j = 1; j < n; ++j) {
            if (grid[i][j] == '.') {
                (dp[i][j] = dp[i - 1][j] + dp[i][j - 1]) %= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
