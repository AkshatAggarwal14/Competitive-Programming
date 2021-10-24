#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, m;
    cin >> n >> m;
    // for each component max ans can be 2^(#nodes in component - 1), thus overall ans is 2^(n - #components)
    ll components = 0;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> vis(n, 0);
    auto dfs = [&](const auto &self, ll parent) -> void {
        vis[parent] = true;
        for (auto &child : adj[parent]) {
            if (vis[child]) continue;
            self(self, child);
        }
    };

    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        components++;
        dfs(dfs, i);
    }

    cout << (1LL << (n - components)) << '\n';
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