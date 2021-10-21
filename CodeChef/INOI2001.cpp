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

void Solution() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> vis(n, 0), dist(n, -1);
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll mn = LLONG_MAX, mx = -1, len = 0;
    auto dfs = [&](const auto &self, ll parent) -> void {
        vis[parent] = 1;
        len++;
        mn = min(mn, parent);
        mx = max(mx, parent);
        for (ll &child : g[parent]) {
            if (vis[child]) continue;
            self(self, child);
        }
    };
    // for leader for each even and odd, push into respective queues and carry 2 bfs
    queue<ll> bfs[2];
    for (ll i = 0; i < n; ++i) {
        if (vis[i]) continue;
        mn = LLONG_MAX, mx = -1, len = 0;
        dfs(dfs, i);
        ll t = len % 2 ? mx : mn;
        bfs[len % 2].emplace(t);
        dist[t] = 1;
    }
    vector<ll> ans(2, 0);
    for (ll I = 0; I < 2; ++I) {
        ans[I] = 0;
        while (!bfs[I].empty()) {
            ll parent = bfs[I].front();
            bfs[I].pop();
            ans[I] += dist[parent];
            for (ll &child : g[parent]) {
                if (dist[child] != -1) continue;  // no need as tree
                dist[child] = dist[parent] + 1;
                bfs[I].emplace(child);
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}