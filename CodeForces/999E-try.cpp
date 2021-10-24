#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, m, s;
    cin >> n >> m >> s;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    vector<ll> vis(n, 0);
    ll components = 0;
    auto dfs = [&](const auto &self, ll parent) -> void {
        if (vis[parent]) return;
        vis[parent] = 1;
        for (ll &child : adj[parent]) {
            if (vis[child]) continue;
            self(self, child);
        }
    };
    dbg(adj);
    dfs(dfs, s - 1);
    components++;
    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        components++;
        dfs(dfs, i);
    }
    cout << components - 1 << '\n';
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