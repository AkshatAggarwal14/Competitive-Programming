#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e10;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> cost(n, vector<ll>(n, INF));

    for (ll i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c, u--, v--;
        cost[u][v] = c;
    }

    for (ll i = 0; i < n; i++) {
        cost[i][i] = 0;
    }

    // cost[i][j] = cost of shortest path from i to j - floyd warshall
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (cost[i][k] == INF or cost[k][j] == INF) continue;
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    // dp[S][i] = The minimum total weight of the edges traversed for walks ending at i with mask S
    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));

    for (ll i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }

    for (ll mask = 1; mask < (1 << n); mask++) {
        for (ll i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                if (dp[mask][i] == INF) continue;
                for (ll j = 0; j < n; j++) {
                    if (!((mask >> j) & 1)) {
                        if (cost[i][j] == INF) continue;
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + cost[i][j]);
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (ll i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    if (ans == INF) {
        cout << "No\n";
        return;
    }
    cout << ans << "\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
