#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto& container) -> ll { return container.size(); };

void bfs_approach() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<pair<ll, ll>> edges;  // store edges to check later
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> d(n, -1);  // use to store ans as well as check visited
    queue<ll> bfs;
    for (ll i = 0; i < n; ++i) {  // kinda like multisouce bfs
        if (d[i] != -1) continue;
        bfs.push(i), d[i] = 1;
        while (!bfs.empty()) {
            ll parent = bfs.front();
            bfs.pop();
            for (ll& child : g[parent]) {
                if (d[child] != -1) continue;
                d[child] = (d[parent] % 2) + 1;
                bfs.push(child);
            }
        }
    }

    for (pair<ll, ll>& t : edges) {
        if (d[t.first] == d[t.second]) {  // if same edge connects equal then NO
            return void(cout << "IMPOSSIBLE");
        }
    }
    for (auto& x : d) cout << x << ' ';
}

void dfs_approach() {
    ll n, m, u, v;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<ll> d(n, -1);  // use to store ans as well as check visited
    function<bool(ll, ll)> dfs = [&](ll parent, ll color) -> bool {
        if (d[parent] != -1) return (d[parent] == color);
        d[parent] = color;
        for (ll& child : g[parent])
            if (!dfs(child, color ^ 1))
                return false;
        return true;
    };
    for (ll i = 0; i < n; i++) {
        if (d[i] == -1 and !dfs(i, 0)) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    for (auto& x : d) cout << x + 1 << ' ';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    bfs_approach();
    // dfs_approach();
    return 0;
}