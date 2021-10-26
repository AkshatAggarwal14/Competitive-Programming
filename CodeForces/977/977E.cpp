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

//! only need simple cycles, all nodes with degree 2 in cycle
void Solution() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> curr_component, vis(n, 0);
    function<void(ll)> dfs = [&](ll node) {
        vis[node] = 1;
        curr_component.push_back(node);
        for (auto &option : g[node]) {
            if (vis[option]) continue;
            dfs(option);
        }
    };
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        curr_component.clear();
        dfs(i);
        bool is_cycle = true;
        for (auto &node : curr_component)
            if (sz(g[node]) != 2) is_cycle = false;  //! sz(g[node]) == degree
        if (is_cycle) ans++;
    }
    cout << ans << '\n';
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