#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (auto &x : grid)
        for (auto &y : x) cin >> y;
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    // dp[i][j] = minimized maximum value over path from (i, j) to (n, m)
    for (ll i = n - 1; i >= 0; --i) {
        for (ll j = m - 1; j >= 0; --j) {
            if (i == n - 1 and j == m - 1)
                dp[i][j] = grid[i][j];
            else if (i == n - 1)
                dp[i][j] = max(grid[i][j], dp[i][j + 1]);
            else if (j == m - 1)
                dp[i][j] = max(grid[i][j], dp[i + 1][j]);
            else {
                if ((i + j) % 2 == 0) {  // Becky
                    dp[i][j] = max(grid[i][j], min(dp[i + 1][j], dp[i][j + 1]));
                } else {  // Anya
                    if (grid[i + 1][j] > grid[i][j + 1])
                        dp[i][j] = max(grid[i][j], dp[i + 1][j]);
                    else
                        dp[i][j] = max(grid[i][j], dp[i][j + 1]);
                }
            }
        }
    }
    cout << dp[0][0] << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
