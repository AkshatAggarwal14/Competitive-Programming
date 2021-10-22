#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
const ll inf = LLONG_MAX;

void Solution() {
    ll n, m, u, v, w;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (ll i = 0; i < n; ++i) dist[i][i] = 0;
    // Floyd Warshall to find all costs
    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (dist[i][k] == inf || dist[k][j] == inf) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = -1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (dist[i][j] == inf) continue;
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}