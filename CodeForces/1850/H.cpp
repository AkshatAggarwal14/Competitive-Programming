#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, -d});
        edges[i] = {u, v, d};
    }

    vector<ll> vals(n + 1, INF);
    queue<ll> bfs;
    for (ll src = 1; src <= n; ++src) {
        if (vals[src] != INF) continue;
        bfs.push(src);
        vals[src] = 0;
        while (!bfs.empty()) {
            ll par = bfs.front();
            bfs.pop();
            for (auto &[child, wt] : g[par]) {
                if (vals[child] == INF) {
                    bfs.push(child);
                    vals[child] = vals[par] + wt;
                }
            }
        }
    }

    for (ll i = 0; i < m; ++i) {
        auto &[u, v, wt] = edges[i];
        if (vals[v] != vals[u] + wt) return void(cout << "NO\n");
    }

    cout << "YES\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
