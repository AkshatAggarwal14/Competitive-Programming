#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
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
    vector<vector<pair<ll, ll>>> g(n);
    ll u, v, color;
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v >> color;
        g[u - 1].push_back({v - 1, color});
        g[v - 1].push_back({u - 1, color});
    }

    vector<ll> vis(n, 0);
    auto dfs = [&](const auto &self, ll parent, ll cc) -> void {
        vis[parent] = 1;
        for (auto &child : g[parent]) {
            if (vis[child.first] || child.second != cc) continue;
            self(self, child.first, cc);
        }
    };

    ll q, ctr;
    cin >> q;
    while (q--) {
        cin >> u >> v;
        ctr = 0;
        for (ll i = 1; i <= m; ++i) {
            vis.assign(n, 0);
            dfs(dfs, u, i);
            if (vis[v]) ctr++;
        }
        cout << ctr << '\n';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}