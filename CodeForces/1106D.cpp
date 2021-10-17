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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    vector<ll> vis(n, 0);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    // do bfs with priority queue instead of normal queue
    vector<ll> ans;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        ll parent = q.top();
        q.pop();
        ans.push_back(parent + 1);
        for (auto child : adj[parent]) {
            if (vis[child]) continue;
            vis[child] = 1;
            q.push(child);
        }
    }
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
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